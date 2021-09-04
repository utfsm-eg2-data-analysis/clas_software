#include "cpp_headers.hh"
#include "root.hh"
#include "dvect.hh"
#include "bos_interface.hh"
#include "bos_funcs.hh"
#include "funcs.hh"

#define MAXTT 200

BOSbank bcs_; 
BOSbank wcs_; 

vector <int>    part_ipdg;
vector <string> part_name;
vector <double> part_chrg;
vector <double> part_mass;
vector <double> part_ltime;
vector <double> part_width;

clasHEAD_t *HEAD;
clasMCEV_t *MCEV;
clasMCTK_t *MCTK;
clasMCVX_t *MCVX;
clasPART_t *PART;

int main(int argc,char *argv[])
{
  if( argc == 1 )
  {
    cout << "missing options" << endl;
    print_usage(); exit(0);
  }

  int iMCTK(0), iPART(0);
  vector<string> vs;
  stringstream ss; ss.str("");
  int max_evnts=-1;

  string rootfile, bosfile;

  int ip=0;
  while( ++ip < argc )
  {
    ss << argv[ip];
    if ( ss.str() == "--b")
    {
      ss.str("");ss << argv[++ip]; 
      while(ss.str().substr(0,2) != "--" && ip < argc )
      {
        vs.push_back(ss.str());
        ss.str("");ip++;ss << argv[ip];
      }
      ip--;
    }
    else if ( ss.str() == "--i")
    {
      ss.str("");ss << argv[++ip];       
      rootfile = ss.str();
    }
    else if ( ss.str() == "--o")
    {
      ss.str("");ss << argv[++ip];       
      bosfile = ss.str();
    }
    else if ( ss.str() == "--n")
    {
      ss.str("");ss << argv[++ip];       
      max_evnts = atoi(ss.str().c_str());
    }
    else
    {
      cout << "check options " << endl;
      print_usage(); exit(0);
    }
    ss.str("");
  }

  if( vs.size() == 0 ) 
  {
    cout << "list of banks is empty" << endl;
    print_usage(); exit(0); 
  }

  for(unsigned int j=0; j<vs.size(); j++)
  {
    if(vs.at(j) == "PART")
    {
      iPART = 1;
    }
    else if(vs.at(j) == "MCTK")
    {
      iMCTK = 1;
    }
    else
    {
      cout << "unrecognized bank " << endl;
      print_usage();exit(0);
    }
  }

  if(rootfile.size() == 0 )
  {
    cout <<"root file not provided"<<endl;
    print_usage();exit(0);
  }

  if(file_exists(rootfile) )
  {
    cout << "root file does not exist" << endl; 
    exit(0);
  }   

  if(bosfile.size() == 0)
  {
    cout <<"bos file not provided"<<endl;
    print_usage();exit(0);
  }
  cout <<endl;
  cout << "root file: " << rootfile << endl;
  cout << "bos file: " << bosfile << endl;
  cout << "banks: ";
  for(unsigned int j=0; j<vs.size(); j++) {cout <<vs.at(j)<<" ";} cout<<endl;

  init_part();

  TFile *f = new TFile(rootfile.c_str());
  TIter mykey( f->GetListOfKeys());
  TKey *key;
  TTree *tr;
  while ((key = (TKey*)mykey()))
  {
    TObject *obj = key->ReadObj();
    if( obj->IsA()->InheritsFrom( TTree::Class() ) )
    {
      tr = (TTree*)obj;
      break;
    }
  }

  int indx;
  dvec p_v;
  double mass;
  int pdg[MAXTT], charge[MAXTT];
  double px[MAXTT], py[MAXTT], pz[MAXTT], p[MAXTT], E[MAXTT];

  int iev;
  int A;
  int neu;
  int hitnuc;
  double pxv, pyv, pzv, Ev;
  double pxn, pyn, pzn, En;
  double pxl, pyl, pzl, pl, El;
  double vtxx,vtxy,vtxz,vtxt;
  int nf;
  int pdgf[MAXTT];
  double pxf[MAXTT], pyf[MAXTT], pzf[MAXTT], pf[MAXTT], Ef[MAXTT];

  tr->SetBranchAddress("iev",     &iev);
  tr->SetBranchAddress("A",       &A);
  tr->SetBranchAddress("neu",     &neu);
  tr->SetBranchAddress("hitnuc",  &hitnuc);
  tr->SetBranchAddress("Ev",      &Ev);
  tr->SetBranchAddress("pxv",     &pxv);
  tr->SetBranchAddress("pyv",     &pyv);
  tr->SetBranchAddress("pzv",     &pzv);
  tr->SetBranchAddress("En",      &En);
  tr->SetBranchAddress("pxn",     &pxn);
  tr->SetBranchAddress("pyn",     &pyn);
  tr->SetBranchAddress("pzn",     &pzn);
  tr->SetBranchAddress("El",      &El);
  tr->SetBranchAddress("pxl",     &pxl);
  tr->SetBranchAddress("pyl",     &pyl);
  tr->SetBranchAddress("pzl",     &pzl);
  tr->SetBranchAddress("pl",      &pl);
  tr->SetBranchAddress("nf",      &nf);
  tr->SetBranchAddress("pdgf",    pdgf);
  tr->SetBranchAddress("Ef",      Ef);
  tr->SetBranchAddress("pf",      pf);  
  tr->SetBranchAddress("pxf",     pxf);
  tr->SetBranchAddress("pyf",     pyf);
  tr->SetBranchAddress("pzf",     pzf);
  tr->SetBranchAddress("vtxx",    &vtxx);
  tr->SetBranchAddress("vtxy",    &vtxy);
  tr->SetBranchAddress("vtxz",    &vtxz);
  tr->SetBranchAddress("vtxt",    &vtxt);

  int Nevts = (int)tr->GetEntries();
  Nevts = ( max_evnts > 0) ? min(max_evnts, Nevts) : Nevts;
  cout << "number of events to be proceeded: " << Nevts << endl<<endl;

  int lun=2;
  if( open_wbos(lun,bosfile) == 0 ) exit(0);

  init_bos();
  map_banks();

  string bnk_head = "HEAD";
  string bnk_part = "PART";
  string bnk_mctk = "MCTK";
  string bnk_mcvx = "MCVX";
  string bnk_all  = "HEADPARTMCTKMCVX";
  string bnk_opt1 = "E=";
  string bnk_opt2 = "E";
  bankList(&bcs_, bnk_opt1, bnk_all);  

  // Make the banks for event 0.
  HEAD = (clasHEAD_t *)makeBank(&bcs_, bnk_head, 0, sizeof(head_t)/sizeof(int), 1);
  fill_header(HEAD, 0);
  putBOS(&bcs_, lun ,bnk_all);      // Write the event.
  dropBank(&bcs_, bnk_head, 0);     // Drop the Head bank.

  for(int ie=0;ie<Nevts;ie++)
  {
    if( (ie%100) == 0 ) {cout <<"event "<< ie <<endl;}

    tr->GetEntry(ie);

    //scatt elec
    px[0] = pxl;
    py[0] = pyl;
    pz[0] = pzl;
    p_v.fillxyz(px[0],py[0],pz[0]);
    p[0] = p_v.mag();
    E[0] = El;
    pdg[0] = neu;
    indx   = part_index(pdg[0]);
    charge[0] = part_chrg.at(indx); 

    //the rest
    for(int it=0; it<nf; it++)
    {
      int iit=it+1;
      px[iit]     = pxf[it];
      py[iit]     = pyf[it];
      pz[iit]     = pzf[it];
      p_v.fillxyz(pxf[it],pyf[it],pzf[it]);
      p[iit]      = p_v.mag();
      E[iit]      = Ef[it];
      pdg[iit]    = pdgf[it];
      indx        = part_index(pdgf[it]);
      charge[iit] = part_chrg.at(indx);      
    }

    // Make the banks.
    HEAD = (clasHEAD_t *)makeBank(&bcs_, bnk_head, 0, sizeof(head_t)/sizeof(int), 1);
    fill_header(HEAD,ie+1);

    if(iPART)
    {
      PART = (clasPART_t *)makeBank(&bcs_, bnk_part, 0, sizeof(part_t)/sizeof(int), nf+1);

      //loop over track
      for(int it=0; it<nf+1; it++) 
      {
        p_v.fillxyz(px[it],py[it],pz[it]);
        fill_part(PART, it, p_v, E[it], charge[it], pdg[it]);
      }//loop over track
    }
    else if(iMCTK)
    {
      MCTK = (clasMCTK_t *)makeBank(&bcs_, bnk_mctk, 0, sizeof(mctk_t)/sizeof(int), nf+1);
      MCVX = (clasMCVX_t *)makeBank(&bcs_, bnk_mcvx, 0, sizeof(mcvx_t)/sizeof(int), nf+1);

      //loop over track
      for(int it=0; it<nf+1; it++) 
      {
        p_v.fillxyz(px[it],py[it],pz[it]);
        indx   = part_index(pdg[it]);
        mass   = part_mass.at(indx);
        fill_mctk(MCTK, it, p_v, mass, charge[it], pdg[it]);
        fill_mcvx(MCVX,it,0.,0.,0.,0.);
      }//loop over track
    }
    putBOS(&bcs_, lun, bnk_opt2); // Write the event.
    dropAllBanks(&bcs_, bnk_opt2);
    cleanBanks(&bcs_);
  }//loop over events

  close_bos(lun);

  return 0;
}


void print_usage()
{
   cout << "usage: root2bos <options> " << endl;
   cout << "options: " << endl;
   cout << "--n <n> #event to be read. if <n> <=0 all events will be proceeded" << endl;
   cout << "--b <list_of_banks> list of banks to be filled PART,MCTK" << endl;
   cout << "--i <root_file>" << endl;
   cout << "--o <bos_file>" << endl;
}
