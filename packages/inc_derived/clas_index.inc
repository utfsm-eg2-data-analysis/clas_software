
      integer N_DDL_BANKS
      parameter (N_DDL_BANKS = 208)
      integer INDEX_TO_BANKS(N_DDL_BANKS),INDEX16_TO_BANKS(N_DDL_BANKS)
      integer WHICH_ARRAY(N_DDL_BANKS)
      character*4 ddl_bank_names(N_DDL_BANKS)
        integer  TPCH_ind, TDPL_ind, DSPS_ind, PID5_ind
        integer  L2S_ind, ECPC_ind, BEAM_ind, L1PG_ind
        integer  MCEV_ind, ECCA_ind, TAGR_ind, SCPE_ind
        integer  FBPM_ind, SH_ind, CCMT_ind, TRCF_ind
        integer  TATL_ind, GPID_ind, EID0_ind, SCT_ind
        integer  RNLG_ind, DSTC_ind, HCAL_ind, MCHD_ind
        integer  STR_ind, HDPL_ind, ECP_ind, PRTM_ind
        integer  ECG_ind, TESC_ind, SPAR_ind, STS_ind
        integer  PID3_ind, DCV1_ind, GPAR_ind, TATR_ind
        integer  PID6_ind, EPIC_ind, RTSL_ind, TAGM_ind
        integer  DGEO_ind, SCRC_ind, CPED_ind, EC1R_ind
        integer  SCC_ind, RUNC_ind, TRL1_ind, ECS_ind
        integer  CCH_ind, CHI2_ind, STH_ind, MTRK_ind
        integer  PCO_ind, SCH_ind, EC_ind, DITM_ind
        integer  EVNT_ind, RC26_ind, TCSB_ind, PHTM_ind
        integer  TAGT_ind, ECRB_ind, HBLA_ind, CALB_ind
        integer  TSRG_ind, MS1_ind, RF_ind, LSRT_ind
        integer  TAGE_ind, DPCP_ind, DTCP_ind, TGTR_ind
        integer  DOCA_ind, RFT_ind, KFIT_ind, MVRT_ind
        integer  CCRC_ind, HBID_ind, BMPR_ind, SCMW_ind
        integer  G4SL_ind, MCVX_ind, TGPB_ind, BREP_ind
        integer  ECPE_ind, DCGW_ind, EC1P_ind, SCS_ind
        integer  CLST_ind, ST1_ind, GGEO_ind, DTRK_ind
        integer  PSO_ind, STN1_ind, S1ST_ind, TRGS_ind
        integer  PID2_ind, TRPB_ind, CSQL_ind, SCMD_ind
        integer  SCP_ind, GP_X_ind, ECMT_ind, ECCL_ind
        integer  LCDI_ind, TPC_ind, TACO_ind, EC1_ind
        integer  SGMP_ind, TLV1_ind, EC01_ind, ICHB_ind
        integer  DCV3_ind, DC1_ind, LOWQ_ind, CC1_ind
        integer  CC01_ind, HEAD_ind, RCST_ind, CL01_ind
        integer  TSPR_ind, PTDB_ind, TGEO_ind, PID4_ind
        integer  ECHB_ind, TBTR_ind, SCPB_ind, ECPO_ind
        integer  DCV2_ind, VERT_ind, TRKS_ind, HLB_ind
        integer  STSN_ind, LASR_ind, TAGI_ind, CCS_ind
        integer  DDLY_ind, TBER_ind, HEVT_ind, STN0_ind
        integer  G3SL_ind, TGBI_ind, SC_ind, HBTB_ind
        integer  STRE_ind, ECPI_ind, SCGD_ind, ECDI_ind
        integer  PART_ind, DC0_ind, SCPS_ind, SHT_ind
        integer  ECH_ind, TBLA_ind, CCPE_ind, HBER_ind
        integer  CCT_ind, SYNC_ind, DCH_ind, HBTR_ind
        integer  ICPB_ind, UNUS_ind, SHHB_ind, STPB_ind
        integer  HLS_ind, L2H_ind, MCTK_ind, GCPB_ind
        integer  ECT_ind, LCPB_ind, DCDW_ind, PIDT_ind
        integer  ECPB_ind, CCDI_ind, DCPB_ind, DHCL_ind
        integer  CCPB_ind, DCMN_ind, TGS_ind, STG_ind
        integer  DCGM_ind, G2SL_ind, ST_ind, CALL_ind
        integer  SHPB_ind, SCR_ind, IC_ind, RC28_ind
        integer  REF_ind, SCG_ind, SPIN_ind, ECCT_ind
        integer  RNPE_ind, TCT_ind, PID1_ind, ECP1_ind
        integer  SCMT_ind, GP_Y_ind, SCDI_ind, TGTL_ind
        integer  CC_ind, TBID_ind, SC1_ind, RGLK_ind
        integer  DPSP_ind, G1SL_ind, STPE_ind, DSPC_ind

        integer  TPCH_ind16, TDPL_ind16, DSPS_ind16, PID5_ind16
        integer  L2S_ind16, ECPC_ind16, BEAM_ind16, L1PG_ind16
        integer  MCEV_ind16, ECCA_ind16, TAGR_ind16, SCPE_ind16
        integer  FBPM_ind16, SH_ind16, CCMT_ind16, TRCF_ind16
        integer  TATL_ind16, GPID_ind16, EID0_ind16, SCT_ind16
        integer  RNLG_ind16, DSTC_ind16, HCAL_ind16, MCHD_ind16
        integer  STR_ind16, HDPL_ind16, ECP_ind16, PRTM_ind16
        integer  ECG_ind16, TESC_ind16, SPAR_ind16, STS_ind16
        integer  PID3_ind16, DCV1_ind16, GPAR_ind16, TATR_ind16
        integer  PID6_ind16, EPIC_ind16, RTSL_ind16, TAGM_ind16
        integer  DGEO_ind16, SCRC_ind16, CPED_ind16, EC1R_ind16
        integer  SCC_ind16, RUNC_ind16, TRL1_ind16, ECS_ind16
        integer  CCH_ind16, CHI2_ind16, STH_ind16, MTRK_ind16
        integer  PCO_ind16, SCH_ind16, EC_ind16, DITM_ind16
        integer  EVNT_ind16, RC26_ind16, TCSB_ind16, PHTM_ind16
        integer  TAGT_ind16, ECRB_ind16, HBLA_ind16, CALB_ind16
        integer  TSRG_ind16, MS1_ind16, RF_ind16, LSRT_ind16
        integer  TAGE_ind16, DPCP_ind16, DTCP_ind16, TGTR_ind16
        integer  DOCA_ind16, RFT_ind16, KFIT_ind16, MVRT_ind16
        integer  CCRC_ind16, HBID_ind16, BMPR_ind16, SCMW_ind16
        integer  G4SL_ind16, MCVX_ind16, TGPB_ind16, BREP_ind16
        integer  ECPE_ind16, DCGW_ind16, EC1P_ind16, SCS_ind16
        integer  CLST_ind16, ST1_ind16, GGEO_ind16, DTRK_ind16
        integer  PSO_ind16, STN1_ind16, S1ST_ind16, TRGS_ind16
        integer  PID2_ind16, TRPB_ind16, CSQL_ind16, SCMD_ind16
        integer  SCP_ind16, GP_X_ind16, ECMT_ind16, ECCL_ind16
        integer  LCDI_ind16, TPC_ind16, TACO_ind16, EC1_ind16
        integer  SGMP_ind16, TLV1_ind16, EC01_ind16, ICHB_ind16
        integer  DCV3_ind16, DC1_ind16, LOWQ_ind16, CC1_ind16
        integer  CC01_ind16, HEAD_ind16, RCST_ind16, CL01_ind16
        integer  TSPR_ind16, PTDB_ind16, TGEO_ind16, PID4_ind16
        integer  ECHB_ind16, TBTR_ind16, SCPB_ind16, ECPO_ind16
        integer  DCV2_ind16, VERT_ind16, TRKS_ind16, HLB_ind16
        integer  STSN_ind16, LASR_ind16, TAGI_ind16, CCS_ind16
        integer  DDLY_ind16, TBER_ind16, HEVT_ind16, STN0_ind16
        integer  G3SL_ind16, TGBI_ind16, SC_ind16, HBTB_ind16
        integer  STRE_ind16, ECPI_ind16, SCGD_ind16, ECDI_ind16
        integer  PART_ind16, DC0_ind16, SCPS_ind16, SHT_ind16
        integer  ECH_ind16, TBLA_ind16, CCPE_ind16, HBER_ind16
        integer  CCT_ind16, SYNC_ind16, DCH_ind16, HBTR_ind16
        integer  ICPB_ind16, UNUS_ind16, SHHB_ind16, STPB_ind16
        integer  HLS_ind16, L2H_ind16, MCTK_ind16, GCPB_ind16
        integer  ECT_ind16, LCPB_ind16, DCDW_ind16, PIDT_ind16
        integer  ECPB_ind16, CCDI_ind16, DCPB_ind16, DHCL_ind16
        integer  CCPB_ind16, DCMN_ind16, TGS_ind16, STG_ind16
        integer  DCGM_ind16, G2SL_ind16, ST_ind16, CALL_ind16
        integer  SHPB_ind16, SCR_ind16, IC_ind16, RC28_ind16
        integer  REF_ind16, SCG_ind16, SPIN_ind16, ECCT_ind16
        integer  RNPE_ind16, TCT_ind16, PID1_ind16, ECP1_ind16
        integer  SCMT_ind16, GP_Y_ind16, SCDI_ind16, TGTL_ind16
        integer  CC_ind16, TBID_ind16, SC1_ind16, RGLK_ind16
        integer  DPSP_ind16, G1SL_ind16, STPE_ind16, DSPC_ind16

        integer  TPCH_array, TDPL_array, DSPS_array, PID5_array
        integer  L2S_array, ECPC_array, BEAM_array, L1PG_array
        integer  MCEV_array, ECCA_array, TAGR_array, SCPE_array
        integer  FBPM_array, SH_array, CCMT_array, TRCF_array
        integer  TATL_array, GPID_array, EID0_array, SCT_array
        integer  RNLG_array, DSTC_array, HCAL_array, MCHD_array
        integer  STR_array, HDPL_array, ECP_array, PRTM_array
        integer  ECG_array, TESC_array, SPAR_array, STS_array
        integer  PID3_array, DCV1_array, GPAR_array, TATR_array
        integer  PID6_array, EPIC_array, RTSL_array, TAGM_array
        integer  DGEO_array, SCRC_array, CPED_array, EC1R_array
        integer  SCC_array, RUNC_array, TRL1_array, ECS_array
        integer  CCH_array, CHI2_array, STH_array, MTRK_array
        integer  PCO_array, SCH_array, EC_array, DITM_array
        integer  EVNT_array, RC26_array, TCSB_array, PHTM_array
        integer  TAGT_array, ECRB_array, HBLA_array, CALB_array
        integer  TSRG_array, MS1_array, RF_array, LSRT_array
        integer  TAGE_array, DPCP_array, DTCP_array, TGTR_array
        integer  DOCA_array, RFT_array, KFIT_array, MVRT_array
        integer  CCRC_array, HBID_array, BMPR_array, SCMW_array
        integer  G4SL_array, MCVX_array, TGPB_array, BREP_array
        integer  ECPE_array, DCGW_array, EC1P_array, SCS_array
        integer  CLST_array, ST1_array, GGEO_array, DTRK_array
        integer  PSO_array, STN1_array, S1ST_array, TRGS_array
        integer  PID2_array, TRPB_array, CSQL_array, SCMD_array
        integer  SCP_array, GP_X_array, ECMT_array, ECCL_array
        integer  LCDI_array, TPC_array, TACO_array, EC1_array
        integer  SGMP_array, TLV1_array, EC01_array, ICHB_array
        integer  DCV3_array, DC1_array, LOWQ_array, CC1_array
        integer  CC01_array, HEAD_array, RCST_array, CL01_array
        integer  TSPR_array, PTDB_array, TGEO_array, PID4_array
        integer  ECHB_array, TBTR_array, SCPB_array, ECPO_array
        integer  DCV2_array, VERT_array, TRKS_array, HLB_array
        integer  STSN_array, LASR_array, TAGI_array, CCS_array
        integer  DDLY_array, TBER_array, HEVT_array, STN0_array
        integer  G3SL_array, TGBI_array, SC_array, HBTB_array
        integer  STRE_array, ECPI_array, SCGD_array, ECDI_array
        integer  PART_array, DC0_array, SCPS_array, SHT_array
        integer  ECH_array, TBLA_array, CCPE_array, HBER_array
        integer  CCT_array, SYNC_array, DCH_array, HBTR_array
        integer  ICPB_array, UNUS_array, SHHB_array, STPB_array
        integer  HLS_array, L2H_array, MCTK_array, GCPB_array
        integer  ECT_array, LCPB_array, DCDW_array, PIDT_array
        integer  ECPB_array, CCDI_array, DCPB_array, DHCL_array
        integer  CCPB_array, DCMN_array, TGS_array, STG_array
        integer  DCGM_array, G2SL_array, ST_array, CALL_array
        integer  SHPB_array, SCR_array, IC_array, RC28_array
        integer  REF_array, SCG_array, SPIN_array, ECCT_array
        integer  RNPE_array, TCT_array, PID1_array, ECP1_array
        integer  SCMT_array, GP_Y_array, SCDI_array, TGTL_array
        integer  CC_array, TBID_array, SC1_array, RGLK_array
        integer  DPSP_array, G1SL_array, STPE_array, DSPC_array


C define the COMMON BLOCK 


          common /clas_index/
     +        index_to_banks, index16_to_banks, which_array 

C  Now equivalance the array to the individual names
        EQUIVALENCE (INDEX_TO_BANKS(1) , TPCH_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(2) , TDPL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(3) , DSPS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(4) , PID5_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(5) , L2S_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(6) , ECPC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(7) , BEAM_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(8) , L1PG_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(9) , MCEV_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(10) , ECCA_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(11) , TAGR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(12) , SCPE_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(13) , FBPM_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(14) , SH_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(15) , CCMT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(16) , TRCF_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(17) , TATL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(18) , GPID_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(19) , EID0_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(20) , SCT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(21) , RNLG_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(22) , DSTC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(23) , HCAL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(24) , MCHD_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(25) , STR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(26) , HDPL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(27) , ECP_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(28) , PRTM_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(29) , ECG_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(30) , TESC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(31) , SPAR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(32) , STS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(33) , PID3_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(34) , DCV1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(35) , GPAR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(36) , TATR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(37) , PID6_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(38) , EPIC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(39) , RTSL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(40) , TAGM_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(41) , DGEO_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(42) , SCRC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(43) , CPED_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(44) , EC1R_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(45) , SCC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(46) , RUNC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(47) , TRL1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(48) , ECS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(49) , CCH_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(50) , CHI2_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(51) , STH_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(52) , MTRK_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(53) , PCO_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(54) , SCH_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(55) , EC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(56) , DITM_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(57) , EVNT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(58) , RC26_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(59) , TCSB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(60) , PHTM_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(61) , TAGT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(62) , ECRB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(63) , HBLA_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(64) , CALB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(65) , TSRG_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(66) , MS1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(67) , RF_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(68) , LSRT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(69) , TAGE_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(70) , DPCP_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(71) , DTCP_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(72) , TGTR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(73) , DOCA_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(74) , RFT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(75) , KFIT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(76) , MVRT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(77) , CCRC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(78) , HBID_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(79) , BMPR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(80) , SCMW_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(81) , G4SL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(82) , MCVX_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(83) , TGPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(84) , BREP_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(85) , ECPE_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(86) , DCGW_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(87) , EC1P_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(88) , SCS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(89) , CLST_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(90) , ST1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(91) , GGEO_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(92) , DTRK_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(93) , PSO_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(94) , STN1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(95) , S1ST_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(96) , TRGS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(97) , PID2_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(98) , TRPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(99) , CSQL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(100) , SCMD_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(101) , SCP_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(102) , GP_X_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(103) , ECMT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(104) , ECCL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(105) , LCDI_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(106) , TPC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(107) , TACO_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(108) , EC1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(109) , SGMP_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(110) , TLV1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(111) , EC01_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(112) , ICHB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(113) , DCV3_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(114) , DC1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(115) , LOWQ_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(116) , CC1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(117) , CC01_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(118) , HEAD_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(119) , RCST_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(120) , CL01_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(121) , TSPR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(122) , PTDB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(123) , TGEO_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(124) , PID4_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(125) , ECHB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(126) , TBTR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(127) , SCPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(128) , ECPO_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(129) , DCV2_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(130) , VERT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(131) , TRKS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(132) , HLB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(133) , STSN_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(134) , LASR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(135) , TAGI_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(136) , CCS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(137) , DDLY_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(138) , TBER_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(139) , HEVT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(140) , STN0_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(141) , G3SL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(142) , TGBI_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(143) , SC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(144) , HBTB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(145) , STRE_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(146) , ECPI_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(147) , SCGD_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(148) , ECDI_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(149) , PART_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(150) , DC0_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(151) , SCPS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(152) , SHT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(153) , ECH_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(154) , TBLA_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(155) , CCPE_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(156) , HBER_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(157) , CCT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(158) , SYNC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(159) , DCH_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(160) , HBTR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(161) , ICPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(162) , UNUS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(163) , SHHB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(164) , STPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(165) , HLS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(166) , L2H_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(167) , MCTK_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(168) , GCPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(169) , ECT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(170) , LCPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(171) , DCDW_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(172) , PIDT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(173) , ECPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(174) , CCDI_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(175) , DCPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(176) , DHCL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(177) , CCPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(178) , DCMN_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(179) , TGS_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(180) , STG_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(181) , DCGM_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(182) , G2SL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(183) , ST_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(184) , CALL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(185) , SHPB_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(186) , SCR_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(187) , IC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(188) , RC28_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(189) , REF_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(190) , SCG_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(191) , SPIN_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(192) , ECCT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(193) , RNPE_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(194) , TCT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(195) , PID1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(196) , ECP1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(197) , SCMT_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(198) , GP_Y_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(199) , SCDI_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(200) , TGTL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(201) , CC_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(202) , TBID_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(203) , SC1_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(204) , RGLK_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(205) , DPSP_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(206) , G1SL_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(207) , STPE_ind) 
        EQUIVALENCE (INDEX_TO_BANKS(208) , DSPC_ind) 

C  Now equivalance the array to the individual names for the 16 bit banks
        EQUIVALENCE (INDEX16_TO_BANKS(1) , TPCH_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(2) , TDPL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(3) , DSPS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(4) , PID5_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(5) , L2S_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(6) , ECPC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(7) , BEAM_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(8) , L1PG_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(9) , MCEV_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(10) , ECCA_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(11) , TAGR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(12) , SCPE_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(13) , FBPM_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(14) , SH_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(15) , CCMT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(16) , TRCF_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(17) , TATL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(18) , GPID_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(19) , EID0_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(20) , SCT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(21) , RNLG_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(22) , DSTC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(23) , HCAL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(24) , MCHD_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(25) , STR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(26) , HDPL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(27) , ECP_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(28) , PRTM_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(29) , ECG_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(30) , TESC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(31) , SPAR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(32) , STS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(33) , PID3_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(34) , DCV1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(35) , GPAR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(36) , TATR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(37) , PID6_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(38) , EPIC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(39) , RTSL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(40) , TAGM_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(41) , DGEO_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(42) , SCRC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(43) , CPED_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(44) , EC1R_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(45) , SCC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(46) , RUNC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(47) , TRL1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(48) , ECS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(49) , CCH_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(50) , CHI2_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(51) , STH_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(52) , MTRK_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(53) , PCO_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(54) , SCH_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(55) , EC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(56) , DITM_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(57) , EVNT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(58) , RC26_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(59) , TCSB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(60) , PHTM_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(61) , TAGT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(62) , ECRB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(63) , HBLA_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(64) , CALB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(65) , TSRG_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(66) , MS1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(67) , RF_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(68) , LSRT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(69) , TAGE_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(70) , DPCP_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(71) , DTCP_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(72) , TGTR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(73) , DOCA_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(74) , RFT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(75) , KFIT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(76) , MVRT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(77) , CCRC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(78) , HBID_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(79) , BMPR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(80) , SCMW_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(81) , G4SL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(82) , MCVX_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(83) , TGPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(84) , BREP_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(85) , ECPE_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(86) , DCGW_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(87) , EC1P_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(88) , SCS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(89) , CLST_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(90) , ST1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(91) , GGEO_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(92) , DTRK_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(93) , PSO_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(94) , STN1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(95) , S1ST_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(96) , TRGS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(97) , PID2_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(98) , TRPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(99) , CSQL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(100) , SCMD_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(101) , SCP_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(102) , GP_X_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(103) , ECMT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(104) , ECCL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(105) , LCDI_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(106) , TPC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(107) , TACO_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(108) , EC1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(109) , SGMP_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(110) , TLV1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(111) , EC01_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(112) , ICHB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(113) , DCV3_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(114) , DC1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(115) , LOWQ_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(116) , CC1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(117) , CC01_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(118) , HEAD_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(119) , RCST_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(120) , CL01_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(121) , TSPR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(122) , PTDB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(123) , TGEO_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(124) , PID4_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(125) , ECHB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(126) , TBTR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(127) , SCPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(128) , ECPO_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(129) , DCV2_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(130) , VERT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(131) , TRKS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(132) , HLB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(133) , STSN_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(134) , LASR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(135) , TAGI_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(136) , CCS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(137) , DDLY_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(138) , TBER_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(139) , HEVT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(140) , STN0_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(141) , G3SL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(142) , TGBI_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(143) , SC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(144) , HBTB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(145) , STRE_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(146) , ECPI_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(147) , SCGD_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(148) , ECDI_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(149) , PART_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(150) , DC0_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(151) , SCPS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(152) , SHT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(153) , ECH_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(154) , TBLA_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(155) , CCPE_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(156) , HBER_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(157) , CCT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(158) , SYNC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(159) , DCH_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(160) , HBTR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(161) , ICPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(162) , UNUS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(163) , SHHB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(164) , STPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(165) , HLS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(166) , L2H_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(167) , MCTK_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(168) , GCPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(169) , ECT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(170) , LCPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(171) , DCDW_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(172) , PIDT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(173) , ECPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(174) , CCDI_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(175) , DCPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(176) , DHCL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(177) , CCPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(178) , DCMN_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(179) , TGS_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(180) , STG_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(181) , DCGM_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(182) , G2SL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(183) , ST_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(184) , CALL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(185) , SHPB_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(186) , SCR_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(187) , IC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(188) , RC28_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(189) , REF_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(190) , SCG_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(191) , SPIN_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(192) , ECCT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(193) , RNPE_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(194) , TCT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(195) , PID1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(196) , ECP1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(197) , SCMT_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(198) , GP_Y_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(199) , SCDI_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(200) , TGTL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(201) , CC_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(202) , TBID_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(203) , SC1_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(204) , RGLK_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(205) , DPSP_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(206) , G1SL_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(207) , STPE_ind16) 
        EQUIVALENCE (INDEX16_TO_BANKS(208) , DSPC_ind16) 

C  Now equivalance the array which_bank which is a flag to which
     
C  IW or JW array 
        EQUIVALENCE (WHICH_ARRAY(1) , TPCH_array) 
        EQUIVALENCE (WHICH_ARRAY(2) , TDPL_array) 
        EQUIVALENCE (WHICH_ARRAY(3) , DSPS_array) 
        EQUIVALENCE (WHICH_ARRAY(4) , PID5_array) 
        EQUIVALENCE (WHICH_ARRAY(5) , L2S_array) 
        EQUIVALENCE (WHICH_ARRAY(6) , ECPC_array) 
        EQUIVALENCE (WHICH_ARRAY(7) , BEAM_array) 
        EQUIVALENCE (WHICH_ARRAY(8) , L1PG_array) 
        EQUIVALENCE (WHICH_ARRAY(9) , MCEV_array) 
        EQUIVALENCE (WHICH_ARRAY(10) , ECCA_array) 
        EQUIVALENCE (WHICH_ARRAY(11) , TAGR_array) 
        EQUIVALENCE (WHICH_ARRAY(12) , SCPE_array) 
        EQUIVALENCE (WHICH_ARRAY(13) , FBPM_array) 
        EQUIVALENCE (WHICH_ARRAY(14) , SH_array) 
        EQUIVALENCE (WHICH_ARRAY(15) , CCMT_array) 
        EQUIVALENCE (WHICH_ARRAY(16) , TRCF_array) 
        EQUIVALENCE (WHICH_ARRAY(17) , TATL_array) 
        EQUIVALENCE (WHICH_ARRAY(18) , GPID_array) 
        EQUIVALENCE (WHICH_ARRAY(19) , EID0_array) 
        EQUIVALENCE (WHICH_ARRAY(20) , SCT_array) 
        EQUIVALENCE (WHICH_ARRAY(21) , RNLG_array) 
        EQUIVALENCE (WHICH_ARRAY(22) , DSTC_array) 
        EQUIVALENCE (WHICH_ARRAY(23) , HCAL_array) 
        EQUIVALENCE (WHICH_ARRAY(24) , MCHD_array) 
        EQUIVALENCE (WHICH_ARRAY(25) , STR_array) 
        EQUIVALENCE (WHICH_ARRAY(26) , HDPL_array) 
        EQUIVALENCE (WHICH_ARRAY(27) , ECP_array) 
        EQUIVALENCE (WHICH_ARRAY(28) , PRTM_array) 
        EQUIVALENCE (WHICH_ARRAY(29) , ECG_array) 
        EQUIVALENCE (WHICH_ARRAY(30) , TESC_array) 
        EQUIVALENCE (WHICH_ARRAY(31) , SPAR_array) 
        EQUIVALENCE (WHICH_ARRAY(32) , STS_array) 
        EQUIVALENCE (WHICH_ARRAY(33) , PID3_array) 
        EQUIVALENCE (WHICH_ARRAY(34) , DCV1_array) 
        EQUIVALENCE (WHICH_ARRAY(35) , GPAR_array) 
        EQUIVALENCE (WHICH_ARRAY(36) , TATR_array) 
        EQUIVALENCE (WHICH_ARRAY(37) , PID6_array) 
        EQUIVALENCE (WHICH_ARRAY(38) , EPIC_array) 
        EQUIVALENCE (WHICH_ARRAY(39) , RTSL_array) 
        EQUIVALENCE (WHICH_ARRAY(40) , TAGM_array) 
        EQUIVALENCE (WHICH_ARRAY(41) , DGEO_array) 
        EQUIVALENCE (WHICH_ARRAY(42) , SCRC_array) 
        EQUIVALENCE (WHICH_ARRAY(43) , CPED_array) 
        EQUIVALENCE (WHICH_ARRAY(44) , EC1R_array) 
        EQUIVALENCE (WHICH_ARRAY(45) , SCC_array) 
        EQUIVALENCE (WHICH_ARRAY(46) , RUNC_array) 
        EQUIVALENCE (WHICH_ARRAY(47) , TRL1_array) 
        EQUIVALENCE (WHICH_ARRAY(48) , ECS_array) 
        EQUIVALENCE (WHICH_ARRAY(49) , CCH_array) 
        EQUIVALENCE (WHICH_ARRAY(50) , CHI2_array) 
        EQUIVALENCE (WHICH_ARRAY(51) , STH_array) 
        EQUIVALENCE (WHICH_ARRAY(52) , MTRK_array) 
        EQUIVALENCE (WHICH_ARRAY(53) , PCO_array) 
        EQUIVALENCE (WHICH_ARRAY(54) , SCH_array) 
        EQUIVALENCE (WHICH_ARRAY(55) , EC_array) 
        EQUIVALENCE (WHICH_ARRAY(56) , DITM_array) 
        EQUIVALENCE (WHICH_ARRAY(57) , EVNT_array) 
        EQUIVALENCE (WHICH_ARRAY(58) , RC26_array) 
        EQUIVALENCE (WHICH_ARRAY(59) , TCSB_array) 
        EQUIVALENCE (WHICH_ARRAY(60) , PHTM_array) 
        EQUIVALENCE (WHICH_ARRAY(61) , TAGT_array) 
        EQUIVALENCE (WHICH_ARRAY(62) , ECRB_array) 
        EQUIVALENCE (WHICH_ARRAY(63) , HBLA_array) 
        EQUIVALENCE (WHICH_ARRAY(64) , CALB_array) 
        EQUIVALENCE (WHICH_ARRAY(65) , TSRG_array) 
        EQUIVALENCE (WHICH_ARRAY(66) , MS1_array) 
        EQUIVALENCE (WHICH_ARRAY(67) , RF_array) 
        EQUIVALENCE (WHICH_ARRAY(68) , LSRT_array) 
        EQUIVALENCE (WHICH_ARRAY(69) , TAGE_array) 
        EQUIVALENCE (WHICH_ARRAY(70) , DPCP_array) 
        EQUIVALENCE (WHICH_ARRAY(71) , DTCP_array) 
        EQUIVALENCE (WHICH_ARRAY(72) , TGTR_array) 
        EQUIVALENCE (WHICH_ARRAY(73) , DOCA_array) 
        EQUIVALENCE (WHICH_ARRAY(74) , RFT_array) 
        EQUIVALENCE (WHICH_ARRAY(75) , KFIT_array) 
        EQUIVALENCE (WHICH_ARRAY(76) , MVRT_array) 
        EQUIVALENCE (WHICH_ARRAY(77) , CCRC_array) 
        EQUIVALENCE (WHICH_ARRAY(78) , HBID_array) 
        EQUIVALENCE (WHICH_ARRAY(79) , BMPR_array) 
        EQUIVALENCE (WHICH_ARRAY(80) , SCMW_array) 
        EQUIVALENCE (WHICH_ARRAY(81) , G4SL_array) 
        EQUIVALENCE (WHICH_ARRAY(82) , MCVX_array) 
        EQUIVALENCE (WHICH_ARRAY(83) , TGPB_array) 
        EQUIVALENCE (WHICH_ARRAY(84) , BREP_array) 
        EQUIVALENCE (WHICH_ARRAY(85) , ECPE_array) 
        EQUIVALENCE (WHICH_ARRAY(86) , DCGW_array) 
        EQUIVALENCE (WHICH_ARRAY(87) , EC1P_array) 
        EQUIVALENCE (WHICH_ARRAY(88) , SCS_array) 
        EQUIVALENCE (WHICH_ARRAY(89) , CLST_array) 
        EQUIVALENCE (WHICH_ARRAY(90) , ST1_array) 
        EQUIVALENCE (WHICH_ARRAY(91) , GGEO_array) 
        EQUIVALENCE (WHICH_ARRAY(92) , DTRK_array) 
        EQUIVALENCE (WHICH_ARRAY(93) , PSO_array) 
        EQUIVALENCE (WHICH_ARRAY(94) , STN1_array) 
        EQUIVALENCE (WHICH_ARRAY(95) , S1ST_array) 
        EQUIVALENCE (WHICH_ARRAY(96) , TRGS_array) 
        EQUIVALENCE (WHICH_ARRAY(97) , PID2_array) 
        EQUIVALENCE (WHICH_ARRAY(98) , TRPB_array) 
        EQUIVALENCE (WHICH_ARRAY(99) , CSQL_array) 
        EQUIVALENCE (WHICH_ARRAY(100) , SCMD_array) 
        EQUIVALENCE (WHICH_ARRAY(101) , SCP_array) 
        EQUIVALENCE (WHICH_ARRAY(102) , GP_X_array) 
        EQUIVALENCE (WHICH_ARRAY(103) , ECMT_array) 
        EQUIVALENCE (WHICH_ARRAY(104) , ECCL_array) 
        EQUIVALENCE (WHICH_ARRAY(105) , LCDI_array) 
        EQUIVALENCE (WHICH_ARRAY(106) , TPC_array) 
        EQUIVALENCE (WHICH_ARRAY(107) , TACO_array) 
        EQUIVALENCE (WHICH_ARRAY(108) , EC1_array) 
        EQUIVALENCE (WHICH_ARRAY(109) , SGMP_array) 
        EQUIVALENCE (WHICH_ARRAY(110) , TLV1_array) 
        EQUIVALENCE (WHICH_ARRAY(111) , EC01_array) 
        EQUIVALENCE (WHICH_ARRAY(112) , ICHB_array) 
        EQUIVALENCE (WHICH_ARRAY(113) , DCV3_array) 
        EQUIVALENCE (WHICH_ARRAY(114) , DC1_array) 
        EQUIVALENCE (WHICH_ARRAY(115) , LOWQ_array) 
        EQUIVALENCE (WHICH_ARRAY(116) , CC1_array) 
        EQUIVALENCE (WHICH_ARRAY(117) , CC01_array) 
        EQUIVALENCE (WHICH_ARRAY(118) , HEAD_array) 
        EQUIVALENCE (WHICH_ARRAY(119) , RCST_array) 
        EQUIVALENCE (WHICH_ARRAY(120) , CL01_array) 
        EQUIVALENCE (WHICH_ARRAY(121) , TSPR_array) 
        EQUIVALENCE (WHICH_ARRAY(122) , PTDB_array) 
        EQUIVALENCE (WHICH_ARRAY(123) , TGEO_array) 
        EQUIVALENCE (WHICH_ARRAY(124) , PID4_array) 
        EQUIVALENCE (WHICH_ARRAY(125) , ECHB_array) 
        EQUIVALENCE (WHICH_ARRAY(126) , TBTR_array) 
        EQUIVALENCE (WHICH_ARRAY(127) , SCPB_array) 
        EQUIVALENCE (WHICH_ARRAY(128) , ECPO_array) 
        EQUIVALENCE (WHICH_ARRAY(129) , DCV2_array) 
        EQUIVALENCE (WHICH_ARRAY(130) , VERT_array) 
        EQUIVALENCE (WHICH_ARRAY(131) , TRKS_array) 
        EQUIVALENCE (WHICH_ARRAY(132) , HLB_array) 
        EQUIVALENCE (WHICH_ARRAY(133) , STSN_array) 
        EQUIVALENCE (WHICH_ARRAY(134) , LASR_array) 
        EQUIVALENCE (WHICH_ARRAY(135) , TAGI_array) 
        EQUIVALENCE (WHICH_ARRAY(136) , CCS_array) 
        EQUIVALENCE (WHICH_ARRAY(137) , DDLY_array) 
        EQUIVALENCE (WHICH_ARRAY(138) , TBER_array) 
        EQUIVALENCE (WHICH_ARRAY(139) , HEVT_array) 
        EQUIVALENCE (WHICH_ARRAY(140) , STN0_array) 
        EQUIVALENCE (WHICH_ARRAY(141) , G3SL_array) 
        EQUIVALENCE (WHICH_ARRAY(142) , TGBI_array) 
        EQUIVALENCE (WHICH_ARRAY(143) , SC_array) 
        EQUIVALENCE (WHICH_ARRAY(144) , HBTB_array) 
        EQUIVALENCE (WHICH_ARRAY(145) , STRE_array) 
        EQUIVALENCE (WHICH_ARRAY(146) , ECPI_array) 
        EQUIVALENCE (WHICH_ARRAY(147) , SCGD_array) 
        EQUIVALENCE (WHICH_ARRAY(148) , ECDI_array) 
        EQUIVALENCE (WHICH_ARRAY(149) , PART_array) 
        EQUIVALENCE (WHICH_ARRAY(150) , DC0_array) 
        EQUIVALENCE (WHICH_ARRAY(151) , SCPS_array) 
        EQUIVALENCE (WHICH_ARRAY(152) , SHT_array) 
        EQUIVALENCE (WHICH_ARRAY(153) , ECH_array) 
        EQUIVALENCE (WHICH_ARRAY(154) , TBLA_array) 
        EQUIVALENCE (WHICH_ARRAY(155) , CCPE_array) 
        EQUIVALENCE (WHICH_ARRAY(156) , HBER_array) 
        EQUIVALENCE (WHICH_ARRAY(157) , CCT_array) 
        EQUIVALENCE (WHICH_ARRAY(158) , SYNC_array) 
        EQUIVALENCE (WHICH_ARRAY(159) , DCH_array) 
        EQUIVALENCE (WHICH_ARRAY(160) , HBTR_array) 
        EQUIVALENCE (WHICH_ARRAY(161) , ICPB_array) 
        EQUIVALENCE (WHICH_ARRAY(162) , UNUS_array) 
        EQUIVALENCE (WHICH_ARRAY(163) , SHHB_array) 
        EQUIVALENCE (WHICH_ARRAY(164) , STPB_array) 
        EQUIVALENCE (WHICH_ARRAY(165) , HLS_array) 
        EQUIVALENCE (WHICH_ARRAY(166) , L2H_array) 
        EQUIVALENCE (WHICH_ARRAY(167) , MCTK_array) 
        EQUIVALENCE (WHICH_ARRAY(168) , GCPB_array) 
        EQUIVALENCE (WHICH_ARRAY(169) , ECT_array) 
        EQUIVALENCE (WHICH_ARRAY(170) , LCPB_array) 
        EQUIVALENCE (WHICH_ARRAY(171) , DCDW_array) 
        EQUIVALENCE (WHICH_ARRAY(172) , PIDT_array) 
        EQUIVALENCE (WHICH_ARRAY(173) , ECPB_array) 
        EQUIVALENCE (WHICH_ARRAY(174) , CCDI_array) 
        EQUIVALENCE (WHICH_ARRAY(175) , DCPB_array) 
        EQUIVALENCE (WHICH_ARRAY(176) , DHCL_array) 
        EQUIVALENCE (WHICH_ARRAY(177) , CCPB_array) 
        EQUIVALENCE (WHICH_ARRAY(178) , DCMN_array) 
        EQUIVALENCE (WHICH_ARRAY(179) , TGS_array) 
        EQUIVALENCE (WHICH_ARRAY(180) , STG_array) 
        EQUIVALENCE (WHICH_ARRAY(181) , DCGM_array) 
        EQUIVALENCE (WHICH_ARRAY(182) , G2SL_array) 
        EQUIVALENCE (WHICH_ARRAY(183) , ST_array) 
        EQUIVALENCE (WHICH_ARRAY(184) , CALL_array) 
        EQUIVALENCE (WHICH_ARRAY(185) , SHPB_array) 
        EQUIVALENCE (WHICH_ARRAY(186) , SCR_array) 
        EQUIVALENCE (WHICH_ARRAY(187) , IC_array) 
        EQUIVALENCE (WHICH_ARRAY(188) , RC28_array) 
        EQUIVALENCE (WHICH_ARRAY(189) , REF_array) 
        EQUIVALENCE (WHICH_ARRAY(190) , SCG_array) 
        EQUIVALENCE (WHICH_ARRAY(191) , SPIN_array) 
        EQUIVALENCE (WHICH_ARRAY(192) , ECCT_array) 
        EQUIVALENCE (WHICH_ARRAY(193) , RNPE_array) 
        EQUIVALENCE (WHICH_ARRAY(194) , TCT_array) 
        EQUIVALENCE (WHICH_ARRAY(195) , PID1_array) 
        EQUIVALENCE (WHICH_ARRAY(196) , ECP1_array) 
        EQUIVALENCE (WHICH_ARRAY(197) , SCMT_array) 
        EQUIVALENCE (WHICH_ARRAY(198) , GP_Y_array) 
        EQUIVALENCE (WHICH_ARRAY(199) , SCDI_array) 
        EQUIVALENCE (WHICH_ARRAY(200) , TGTL_array) 
        EQUIVALENCE (WHICH_ARRAY(201) , CC_array) 
        EQUIVALENCE (WHICH_ARRAY(202) , TBID_array) 
        EQUIVALENCE (WHICH_ARRAY(203) , SC1_array) 
        EQUIVALENCE (WHICH_ARRAY(204) , RGLK_array) 
        EQUIVALENCE (WHICH_ARRAY(205) , DPSP_array) 
        EQUIVALENCE (WHICH_ARRAY(206) , G1SL_array) 
        EQUIVALENCE (WHICH_ARRAY(207) , STPE_array) 
        EQUIVALENCE (WHICH_ARRAY(208) , DSPC_array) 

C  Define the DDL bank names 
         data  DDL_BANK_NAMES(1)/'TPCH'/ 
         data  DDL_BANK_NAMES(2)/'TDPL'/ 
         data  DDL_BANK_NAMES(3)/'DSPS'/ 
         data  DDL_BANK_NAMES(4)/'PID5'/ 
         data  DDL_BANK_NAMES(5)/'L2S '/ 
         data  DDL_BANK_NAMES(6)/'ECPC'/ 
         data  DDL_BANK_NAMES(7)/'BEAM'/ 
         data  DDL_BANK_NAMES(8)/'L1PG'/ 
         data  DDL_BANK_NAMES(9)/'MCEV'/ 
         data  DDL_BANK_NAMES(10)/'ECCA'/ 
         data  DDL_BANK_NAMES(11)/'TAGR'/ 
         data  DDL_BANK_NAMES(12)/'SCPE'/ 
         data  DDL_BANK_NAMES(13)/'FBPM'/ 
         data  DDL_BANK_NAMES(14)/'SH  '/ 
         data  DDL_BANK_NAMES(15)/'CCMT'/ 
         data  DDL_BANK_NAMES(16)/'TRCF'/ 
         data  DDL_BANK_NAMES(17)/'TATL'/ 
         data  DDL_BANK_NAMES(18)/'GPID'/ 
         data  DDL_BANK_NAMES(19)/'EID0'/ 
         data  DDL_BANK_NAMES(20)/'SCT '/ 
         data  DDL_BANK_NAMES(21)/'RNLG'/ 
         data  DDL_BANK_NAMES(22)/'DSTC'/ 
         data  DDL_BANK_NAMES(23)/'HCAL'/ 
         data  DDL_BANK_NAMES(24)/'MCHD'/ 
         data  DDL_BANK_NAMES(25)/'STR '/ 
         data  DDL_BANK_NAMES(26)/'HDPL'/ 
         data  DDL_BANK_NAMES(27)/'ECP '/ 
         data  DDL_BANK_NAMES(28)/'PRTM'/ 
         data  DDL_BANK_NAMES(29)/'ECG '/ 
         data  DDL_BANK_NAMES(30)/'TESC'/ 
         data  DDL_BANK_NAMES(31)/'SPAR'/ 
         data  DDL_BANK_NAMES(32)/'STS '/ 
         data  DDL_BANK_NAMES(33)/'PID3'/ 
         data  DDL_BANK_NAMES(34)/'DCV1'/ 
         data  DDL_BANK_NAMES(35)/'GPAR'/ 
         data  DDL_BANK_NAMES(36)/'TATR'/ 
         data  DDL_BANK_NAMES(37)/'PID6'/ 
         data  DDL_BANK_NAMES(38)/'EPIC'/ 
         data  DDL_BANK_NAMES(39)/'RTSL'/ 
         data  DDL_BANK_NAMES(40)/'TAGM'/ 
         data  DDL_BANK_NAMES(41)/'DGEO'/ 
         data  DDL_BANK_NAMES(42)/'SCRC'/ 
         data  DDL_BANK_NAMES(43)/'CPED'/ 
         data  DDL_BANK_NAMES(44)/'EC1R'/ 
         data  DDL_BANK_NAMES(45)/'SCC '/ 
         data  DDL_BANK_NAMES(46)/'RUNC'/ 
         data  DDL_BANK_NAMES(47)/'TRL1'/ 
         data  DDL_BANK_NAMES(48)/'ECS '/ 
         data  DDL_BANK_NAMES(49)/'CCH '/ 
         data  DDL_BANK_NAMES(50)/'CHI2'/ 
         data  DDL_BANK_NAMES(51)/'STH '/ 
         data  DDL_BANK_NAMES(52)/'MTRK'/ 
         data  DDL_BANK_NAMES(53)/'PCO '/ 
         data  DDL_BANK_NAMES(54)/'SCH '/ 
         data  DDL_BANK_NAMES(55)/'EC  '/ 
         data  DDL_BANK_NAMES(56)/'DITM'/ 
         data  DDL_BANK_NAMES(57)/'EVNT'/ 
         data  DDL_BANK_NAMES(58)/'RC26'/ 
         data  DDL_BANK_NAMES(59)/'TCSB'/ 
         data  DDL_BANK_NAMES(60)/'PHTM'/ 
         data  DDL_BANK_NAMES(61)/'TAGT'/ 
         data  DDL_BANK_NAMES(62)/'ECRB'/ 
         data  DDL_BANK_NAMES(63)/'HBLA'/ 
         data  DDL_BANK_NAMES(64)/'CALB'/ 
         data  DDL_BANK_NAMES(65)/'TSRG'/ 
         data  DDL_BANK_NAMES(66)/'MS1 '/ 
         data  DDL_BANK_NAMES(67)/'RF  '/ 
         data  DDL_BANK_NAMES(68)/'LSRT'/ 
         data  DDL_BANK_NAMES(69)/'TAGE'/ 
         data  DDL_BANK_NAMES(70)/'DPCP'/ 
         data  DDL_BANK_NAMES(71)/'DTCP'/ 
         data  DDL_BANK_NAMES(72)/'TGTR'/ 
         data  DDL_BANK_NAMES(73)/'DOCA'/ 
         data  DDL_BANK_NAMES(74)/'RFT '/ 
         data  DDL_BANK_NAMES(75)/'KFIT'/ 
         data  DDL_BANK_NAMES(76)/'MVRT'/ 
         data  DDL_BANK_NAMES(77)/'CCRC'/ 
         data  DDL_BANK_NAMES(78)/'HBID'/ 
         data  DDL_BANK_NAMES(79)/'BMPR'/ 
         data  DDL_BANK_NAMES(80)/'SCMW'/ 
         data  DDL_BANK_NAMES(81)/'G4SL'/ 
         data  DDL_BANK_NAMES(82)/'MCVX'/ 
         data  DDL_BANK_NAMES(83)/'TGPB'/ 
         data  DDL_BANK_NAMES(84)/'BREP'/ 
         data  DDL_BANK_NAMES(85)/'ECPE'/ 
         data  DDL_BANK_NAMES(86)/'DCGW'/ 
         data  DDL_BANK_NAMES(87)/'EC1P'/ 
         data  DDL_BANK_NAMES(88)/'SCS '/ 
         data  DDL_BANK_NAMES(89)/'CLST'/ 
         data  DDL_BANK_NAMES(90)/'ST1 '/ 
         data  DDL_BANK_NAMES(91)/'GGEO'/ 
         data  DDL_BANK_NAMES(92)/'DTRK'/ 
         data  DDL_BANK_NAMES(93)/'PSO '/ 
         data  DDL_BANK_NAMES(94)/'STN1'/ 
         data  DDL_BANK_NAMES(95)/'S1ST'/ 
         data  DDL_BANK_NAMES(96)/'TRGS'/ 
         data  DDL_BANK_NAMES(97)/'PID2'/ 
         data  DDL_BANK_NAMES(98)/'TRPB'/ 
         data  DDL_BANK_NAMES(99)/'CSQL'/ 
         data  DDL_BANK_NAMES(100)/'SCMD'/ 
         data  DDL_BANK_NAMES(101)/'SCP '/ 
         data  DDL_BANK_NAMES(102)/'GP_X'/ 
         data  DDL_BANK_NAMES(103)/'ECMT'/ 
         data  DDL_BANK_NAMES(104)/'ECCL'/ 
         data  DDL_BANK_NAMES(105)/'LCDI'/ 
         data  DDL_BANK_NAMES(106)/'TPC '/ 
         data  DDL_BANK_NAMES(107)/'TACO'/ 
         data  DDL_BANK_NAMES(108)/'EC1 '/ 
         data  DDL_BANK_NAMES(109)/'SGMP'/ 
         data  DDL_BANK_NAMES(110)/'TLV1'/ 
         data  DDL_BANK_NAMES(111)/'EC01'/ 
         data  DDL_BANK_NAMES(112)/'ICHB'/ 
         data  DDL_BANK_NAMES(113)/'DCV3'/ 
         data  DDL_BANK_NAMES(114)/'DC1 '/ 
         data  DDL_BANK_NAMES(115)/'LOWQ'/ 
         data  DDL_BANK_NAMES(116)/'CC1 '/ 
         data  DDL_BANK_NAMES(117)/'CC01'/ 
         data  DDL_BANK_NAMES(118)/'HEAD'/ 
         data  DDL_BANK_NAMES(119)/'RCST'/ 
         data  DDL_BANK_NAMES(120)/'CL01'/ 
         data  DDL_BANK_NAMES(121)/'TSPR'/ 
         data  DDL_BANK_NAMES(122)/'PTDB'/ 
         data  DDL_BANK_NAMES(123)/'TGEO'/ 
         data  DDL_BANK_NAMES(124)/'PID4'/ 
         data  DDL_BANK_NAMES(125)/'ECHB'/ 
         data  DDL_BANK_NAMES(126)/'TBTR'/ 
         data  DDL_BANK_NAMES(127)/'SCPB'/ 
         data  DDL_BANK_NAMES(128)/'ECPO'/ 
         data  DDL_BANK_NAMES(129)/'DCV2'/ 
         data  DDL_BANK_NAMES(130)/'VERT'/ 
         data  DDL_BANK_NAMES(131)/'TRKS'/ 
         data  DDL_BANK_NAMES(132)/'HLB '/ 
         data  DDL_BANK_NAMES(133)/'STSN'/ 
         data  DDL_BANK_NAMES(134)/'LASR'/ 
         data  DDL_BANK_NAMES(135)/'TAGI'/ 
         data  DDL_BANK_NAMES(136)/'CCS '/ 
         data  DDL_BANK_NAMES(137)/'DDLY'/ 
         data  DDL_BANK_NAMES(138)/'TBER'/ 
         data  DDL_BANK_NAMES(139)/'HEVT'/ 
         data  DDL_BANK_NAMES(140)/'STN0'/ 
         data  DDL_BANK_NAMES(141)/'G3SL'/ 
         data  DDL_BANK_NAMES(142)/'TGBI'/ 
         data  DDL_BANK_NAMES(143)/'SC  '/ 
         data  DDL_BANK_NAMES(144)/'HBTB'/ 
         data  DDL_BANK_NAMES(145)/'STRE'/ 
         data  DDL_BANK_NAMES(146)/'ECPI'/ 
         data  DDL_BANK_NAMES(147)/'SCGD'/ 
         data  DDL_BANK_NAMES(148)/'ECDI'/ 
         data  DDL_BANK_NAMES(149)/'PART'/ 
         data  DDL_BANK_NAMES(150)/'DC0 '/ 
         data  DDL_BANK_NAMES(151)/'SCPS'/ 
         data  DDL_BANK_NAMES(152)/'SHT '/ 
         data  DDL_BANK_NAMES(153)/'ECH '/ 
         data  DDL_BANK_NAMES(154)/'TBLA'/ 
         data  DDL_BANK_NAMES(155)/'CCPE'/ 
         data  DDL_BANK_NAMES(156)/'HBER'/ 
         data  DDL_BANK_NAMES(157)/'CCT '/ 
         data  DDL_BANK_NAMES(158)/'SYNC'/ 
         data  DDL_BANK_NAMES(159)/'DCH '/ 
         data  DDL_BANK_NAMES(160)/'HBTR'/ 
         data  DDL_BANK_NAMES(161)/'ICPB'/ 
         data  DDL_BANK_NAMES(162)/'UNUS'/ 
         data  DDL_BANK_NAMES(163)/'SHHB'/ 
         data  DDL_BANK_NAMES(164)/'STPB'/ 
         data  DDL_BANK_NAMES(165)/'HLS '/ 
         data  DDL_BANK_NAMES(166)/'L2H '/ 
         data  DDL_BANK_NAMES(167)/'MCTK'/ 
         data  DDL_BANK_NAMES(168)/'GCPB'/ 
         data  DDL_BANK_NAMES(169)/'ECT '/ 
         data  DDL_BANK_NAMES(170)/'LCPB'/ 
         data  DDL_BANK_NAMES(171)/'DCDW'/ 
         data  DDL_BANK_NAMES(172)/'PIDT'/ 
         data  DDL_BANK_NAMES(173)/'ECPB'/ 
         data  DDL_BANK_NAMES(174)/'CCDI'/ 
         data  DDL_BANK_NAMES(175)/'DCPB'/ 
         data  DDL_BANK_NAMES(176)/'DHCL'/ 
         data  DDL_BANK_NAMES(177)/'CCPB'/ 
         data  DDL_BANK_NAMES(178)/'DCMN'/ 
         data  DDL_BANK_NAMES(179)/'TGS '/ 
         data  DDL_BANK_NAMES(180)/'STG '/ 
         data  DDL_BANK_NAMES(181)/'DCGM'/ 
         data  DDL_BANK_NAMES(182)/'G2SL'/ 
         data  DDL_BANK_NAMES(183)/'ST  '/ 
         data  DDL_BANK_NAMES(184)/'CALL'/ 
         data  DDL_BANK_NAMES(185)/'SHPB'/ 
         data  DDL_BANK_NAMES(186)/'SCR '/ 
         data  DDL_BANK_NAMES(187)/'IC  '/ 
         data  DDL_BANK_NAMES(188)/'RC28'/ 
         data  DDL_BANK_NAMES(189)/'REF '/ 
         data  DDL_BANK_NAMES(190)/'SCG '/ 
         data  DDL_BANK_NAMES(191)/'SPIN'/ 
         data  DDL_BANK_NAMES(192)/'ECCT'/ 
         data  DDL_BANK_NAMES(193)/'RNPE'/ 
         data  DDL_BANK_NAMES(194)/'TCT '/ 
         data  DDL_BANK_NAMES(195)/'PID1'/ 
         data  DDL_BANK_NAMES(196)/'ECP1'/ 
         data  DDL_BANK_NAMES(197)/'SCMT'/ 
         data  DDL_BANK_NAMES(198)/'GP_Y'/ 
         data  DDL_BANK_NAMES(199)/'SCDI'/ 
         data  DDL_BANK_NAMES(200)/'TGTL'/ 
         data  DDL_BANK_NAMES(201)/'CC  '/ 
         data  DDL_BANK_NAMES(202)/'TBID'/ 
         data  DDL_BANK_NAMES(203)/'SC1 '/ 
         data  DDL_BANK_NAMES(204)/'RGLK'/ 
         data  DDL_BANK_NAMES(205)/'DPSP'/ 
         data  DDL_BANK_NAMES(206)/'G1SL'/ 
         data  DDL_BANK_NAMES(207)/'STPE'/ 
         data  DDL_BANK_NAMES(208)/'DSPC'/ 
