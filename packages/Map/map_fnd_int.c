/* 
   map_fnd_int.c
   Created           : 30-NOV-1992 by Thom Sulanke
*/
 
#include <stdio.h>                   /* I/O definitions                      */
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <map_manager.h>
#include <map_internal.h>

/***********************************************************************/
/*                                                                     */
/*   MAP_FND_INT                                                       */
/*   -----------                                                       */
/*                                                                     */
/*         Created     : 30-NOV-1992    Author : Thom Sulanke          */
/*         Purpose     : find array of int values in the map.  Return time.*/
/*                       If no values match, firsttime is set to -1.   */
/*                       If error, firsttime is set to -2.             */
/*                                                                     */
/***********************************************************************/
 
int map_fnd_int( const char filename[], const char subsystemname[], 
		const char itemname[], int length, const int array[], 
		int atime, int *firsttime )
     
{
  int fd ;
  pointer_t item_loc, pred_loc, header_loc;
  item_t item;
  arrayheader_t header;
  int *match_array;
  int ia;
  int tindex;  /* table index of pred */
  int status, succ_time;
  table_t *table;
  
  /* set error value in case of early return */
  
  *firsttime = -2;
  
  /* get the current time */
  
  if ( atime == 0 )
    {
      atime = time(NULL);
    }
  
  /* check arguements */
  
  if ( strlen(subsystemname) > MAP_NAMELENGTH-1 )
    {
      map_error(MAP_USER_ERROR_ARGUMENT,
		"map_fnd_int: Subsystem name (%s) longer than %d characters.",
		subsystemname,
		MAP_NAMELENGTH-1);
      return MAP_USER_ERROR_ARGUMENT;
    }
  
  if ( strlen(itemname) > MAP_NAMELENGTH-1 )
    {
      map_error(MAP_USER_ERROR_ARGUMENT,
		"map_fnd_int: Item name (%s) longer than %d characters.",
		itemname,
		MAP_NAMELENGTH-1);
      return MAP_USER_ERROR_ARGUMENT;
    }
  
  /* open file for read */
  
  fd = map_open_ro_lock(filename);
  if ( fd < 0 )
    {
      map_syserror(fd,
		   "map_fnd_int: can't open TheMap (%s)",
		   filename);
      return fd;
    }
  
  /* find item location and read item */
  
  status = map_find_item(fd,subsystemname,itemname,&item_loc);
  if ( status < 0 )
    {
      map_close_map(fd);
      return status;
    }
  status = map_read(&item,sizeof item,fd,item_loc,swapitem);
  if ( status != MAP_OK ) 
    {
      map_close_map(fd);
      return status;
    }
  
  /* check array size */
  
  if ( length != item.length )
    {
      map_error( MAP_USER_ERROR_ARGUMENT,
		"map_fnd_int: Array length (%d) incorrect for subsystem (%s), item (%s).\n Should be %d.",
		length,
		subsystemname,
		itemname,
		item.length);
      map_close_map(fd);
      return MAP_USER_ERROR_ARGUMENT;
    }
  
  /* check array type */
  
  if ( item.type != 0 )
    {
      map_error(MAP_USER_ERROR_ARGUMENT,
		"map_fnd_int: Array type (%d) for subsystem (%s), item (%s) \n requires call to different map_fnd_* routine.",
		item.type,
		subsystemname,
		itemname);
      map_close_map(fd);
      return MAP_USER_ERROR_ARGUMENT;
    }
  
  /* find first (in list) possible array in list */
  
  status = map_time_pred(fd,item_loc+ITEM_LIST_OFFSET,item,atime,&tindex,&header_loc,&succ_time,&pred_loc);

  if ( status < 0 )
    {
      map_close_map(fd);
      return status;
    }
  
  if ( item.list < 0 && item.table_used > 0 )
    {
      tindex++;
      table = (table_t *) calloc(item.table_used,sizeof(table_t));
      status = map_read(table,(item.table_used)*sizeof(table_t),fd,item.table,swaptablearray);
      if ( status != MAP_OK )
	{
	  free(table);
	  map_close_map(fd);
	  return status;
	}
    }

  /* scan list */
  
  match_array = (int *) calloc(item.length,sizeof(int));
  if ( match_array == NULL )
    {
      map_close_map(fd);
      return MAP_SYSTEM_ERROR_MEMORY;
    }
  while ( header_loc != NULL_LOC )
    {
      status = map_read(match_array,item.length*4,fd,header_loc+ARRAY_VALUES_OFFSET,swapintarray);
      if ( status != MAP_OK ) 
	{
	  map_close_map(fd);
	  return status;
	}
      for ( ia=0 ; ia < item.length ; ia++ )
        {
	  if ( match_array[ia] != array[ia] )
            {
	      break;
            }
        }
      if ( ia == item.length )
        {
	  break;
        } 
      if ( item.list > 0 )
	
	/* version 1 */
	
	{
	  status = map_read(&header,sizeof header,fd,header_loc,swaparrayheader);
	  if ( status != MAP_OK ) 
	    {
	      map_close_map(fd);
	      return status;
	    }
	  header_loc = header.next;
	}
      else
	
	/* version 2 */
	
	{
	  tindex++;
	  if ( tindex >= item.table_used )
	    header_loc = NULL_LOC;
	  else
	    header_loc = table[tindex].loc;
	}
      
    }
  if ( item.list < 0 && item.table_used > 0 )
    free(table);

  free(match_array);      
  
  /* check if match was found */
  
  
  if ( header_loc == NULL_LOC )
    {
      *firsttime = -1;
    }
  else
    {
      if ( item.list > 0 )
	/* version 1 */
	{	
	  status = map_read(&header,sizeof header,fd,header_loc,swaparrayheader);
	  if ( status != MAP_OK ) 
	    {
	      map_close_map(fd);
	      return status;
	    }
	  *firsttime = header.time;
	}
      else
	/* version 2 */
	*firsttime = table[tindex].time;
    }
  
  /* close the file */
  
  return map_close_map(fd);
  
}
