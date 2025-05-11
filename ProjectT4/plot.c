Double_t the_lin(Double_t *x, double *par){
    return x[0];
}

void plot()
{
    Double_t Energy[] = {   2.0,3.8,4.0,6.0,8.0,10.0,12.0,14.0,16.0,20.0,40.0,80.0,160.0,320.0,640.0,1280.0,2560.0,5120.0,10240.0,20480.0,40960.0};
    Double_t Total_Counts[] = { 1000000,1000000,999998,999998,1000000,999997,999998,999997,999998,499999,499999,500000,500000,500000,500000,500000,500000,500000,500000,500000,500000};
    Double_t Detected[] = {    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Double_t Full_Energy[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Double_t Primary_Counts[] = {0,0,75197,75676,75824,75937,76699,76018,517,324,658,678,739,21157,43943,43692,43299,43159,42586,42155,    42169};
    Double_t DeltaElectron_Counts[] = {0,0,0,0,0,0,0,0,0,0,0,0,1,243,484,744,984,1121,1264,1380,1314};
    Double_t GammaInvolved_Counts[] = {0,0,14,22,41,66,68,103,139,96,425,1116,1151,1043,1309,1580,1729,1910,2183,2516,2945};
    Double_t NeutronInelastic_Counts[]={0,0,0,0,0,0,0,0,0,0,4,18,27,49,46,53,72,92,123,130,120};
    Double_t ProtonInelastic_Counts[] ={0,0,0,2,1,3,9,9,8,11,38,100,110,160,195,240,264,331,318,275,275};
    Double_t HadronElastic_Counts[] = {0,0,4,7,5,0,4,3,1,1,11,22,31,40,68,54,76,129,139,124,131};
    Double_t Others[] = {              0,0,1,0,0,0,0,0,0,0,1,0,1,0,4,10,18,39,51,58,60};
    Double_t InRange[] = {0,0,75214,75705,75871,76003,76778,76131,665,430,1050,1357,1362,21955,45226,45360,45150,45225,44888,44801,45106};

    Double_t Energy_2[] = {2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,
    3.9,4.0,4.1,4.2,4.3,4.4,4.9,5.4,5.9};
    Double_t Peak[] = {0,0,0,1.56005e-01,5.38552e-01,8.23431e-01,1.06118e+00,
    1.27514e+00,1.47076e+00,1.65779e+00,1.82814e+00,1.99560e+00,};
    Double_t CONSTANT[] = {0,0,0,2.40641e+02,3.43564e+02,3.86885e+02,4.09686e+02,
    4.32741e+02,4.61767e+02,4.63254e+02,4.67665e+02,4.70358e+02,};
    Double_t STDDEV[] = {0,0,0,8.17738e-02,5.93000e-02,5.33231e-02,5.05887e-02,
    4.85070e-02,4.59565e-02,4.58602e-02,4.47485e-02,4.57356e-02,};

    Double_t Energy_3[] = {4.0,4.2,4.4,4.6,4.8,5.0,5.2,5.4,5.6,5.8,6.0,6.5,7.0,7.5,8.0,8.5,9.0,
    9.5,10.0,10.5};
    Double_t Peak_3[] = {5.46622e-01,1.16668e+00,1.62394e+00,2.01596e+00,2.37006e+00,2.69641e+00,
    3.00568e+00,3.30245e+00,3.58789e+00,3.86559e+00,4.13592e+00,4.78472e+00,5.40553e+00,
    6.00761e+00,6.59489e+00,7.17207e+00,7.74141e+00,8.30299e+00,8.85596e+00,9.40306e+00};
    Double_t STDDEV_3[] = {1.18201e-01,8.26674e-02,7.24379e-02, 6.74033e-02,6.43020e-02,6.21444e-02,
    6.08870e-02,5.97379e-02,5.88347e-02,5.80281e-02,5.76358e-02,5.68373e-02,5.58178e-02,
    5.54967e-02,5.49262e-02,5.39707e-02,5.40044e-02,5.38876e-02,5.36405e-02,5.35981e-02};

    // Double_t Energy_4[] = {320,640,1280,2560,5120,10240,20480,40960,480,960,1920,3840,7680,
    // 15360,30720};
    // Double_t Peak_4[] = {1.51198e+01,1.04867e+01,8.73802e+00,8.13397e+00,8.08508e+00,8.21479e+00,
    // 8.39048e+00,8.53343e+00,1.23070e+01,9.26682e+00,8.27859e+00,8.07070e+00,8.15570e+00,8.32926e+00,
    // 8.46573e+00};
    // Double_t STDDEV_4[] = {8.41830e-01,7.67251e-01,3.70588e-01,4.14194e-01,4.39882e-01, 4.50081e-01,
    // 4.61536e-01,4.64423e-01,7.89094e-01,7.40260e-01,3.88762e-01,4.19034e-01,4.37032e-01,4.51471e-01,
    // 4.48460e-01};

    Double_t Energy_4[] = {320,480,640,960,1280,1920,2560,3840,5120,7680,10240,15360,20480,
    30720,40960};
    Double_t Peak_4[] = {1.51198e+01,1.23070e+01,1.04867e+01,9.26682e+00,8.73802e+00,8.27859e+00,
    8.13397e+00,8.07070e+00,8.08508e+00,8.15570e+00,8.21479e+00,8.32926e+00,
    8.39048e+00,8.46573e+00,8.53343e+00};
    Double_t STDDEV_4[] = {8.41830e-01,7.89094e-01,7.67251e-01,7.40260e-01,3.70588e-01,3.88762e-01,
    4.14194e-01,4.19034e-01,4.39882e-01,4.37032e-01, 4.50081e-01,4.51471e-01,
    4.61536e-01,4.48460e-01,4.64423e-01
    };

   //  TF1 *lin = new TF1("lin",the_lin,3,11,0);
   //  auto c1 = new TCanvas("c1","Delta E - E Plot @ Low Energy");
   //  auto gr = new TGraphErrors(20,Energy_3,Peak_3,nullptr,STDDEV_3);
   //  gr->SetTitle("Delta E - E Plot @ Low Energy (proton, front)");
   //  gr->GetXaxis()->SetTitle("E/MeV");
   //  gr->GetYaxis()->SetTitle("Delta E/MeV");
   //  gr->SetMinimum(0);
   //  cout<<gr->GetYaxis()->GetXmin()<<endl;
   //  gr->Draw("ALP");
   //  lin->Draw("Same");
   //  c1->Update();

   // Double_t Energy_5[] = {  2,4,8,16,32,64,128,256,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2500,3000,3500,4000,4500,5000,5500,8000,16000,32000 };
   //  Double_t Total_Counts_5[] = {100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,500000,500000,,,,100000,,,,100000,100000,100000};
   //  Double_t Primary_Counts_5[] = {0,0,0,0,0,435,170,227,7912,8185,8348,8247,8296,8275,8316,8232,8217,8365,8129,8251,8092,8121,8234,40929,41023,,,,8054,,,,7982,7823,7950};
   //  Double_t DeltaElectron_Counts_5[] = {0,0,0,0,0,0,0,17,51,87,114,132,146,157,179,226,215,233,240,267,270,323,319,1608,1587,,,,474,,,,687,855,961};
   //  Double_t GammaInvolved_Counts_5[] = {1,0,0,1,19,112,226,242,257,281,283,327,341,379,331,396,374,393,394,438,448,465,416,2312,2386,,,,592,,,,798,898,962};
   //  Double_t NeutronInelastic_Counts_5[]={0,0,0,0,0,2,6,8,8,14,12,13,11,13,16,14,18,14,18,14,19,20,20,99,110,,,,24,,,,29,36,26};
   //  Double_t ProtonInelastic_Counts_5[] ={0,0,0,0,1,13,38,53,95,153,148,201,251,223,264,250,263,280,246,257,249,244,312,1473,1555,,,,339,,,,324,297,237};
   //  Double_t HadronElastic_Counts_5[] = {0,0,0,0,0,4,14,13,19,12,14,16,19,18,19,24,17,17,17,21,22,16,20,29,117,120,,,,25,,,,28,22,38};
   //  Double_t Others_5[] = {0,0,0,0,0,0,0,0,0,0,0,1,3,4,0,3,6,3,5,4,5,8,3,24,37,,,,8,,,,25,37,37};
   //  Double_t InRange_5[] = {1,0,0,1,20,546,371,419,8195,8555,8745,8748,8872,8833,8920,8900,8876,9077,8796,8984,8857,8931,9066,45105,45344,,,,9130,,,,9218,9085,9281};

   Double_t Energy_6[] = {400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2500,3000,3500,4000,4500,5000,5500,8000,16000,32000};
    Double_t Peak_6[] = {1.36543e+01,12.155297,11.019323,10.235618,9.8030844,9.4003770,9.1844497,8.9681135,8.8095663,8.6733556,8.5366239,8.4669364,8.4276937,8.2994716,8.2457439,8.2808840,8.2323802,8.0994206,8.0681794,8.0108222,8.0185500,8.0147377,8.0342620,8.0214359,8.0834987,8.2693518,8.4433458};
   //  Double_t STDDEV_6[] = {8.04725e-01,8.13154e-01,7.93651e-01,7.79553e-01,};
   

   Double_t Energy_5[] = {  2,4,8,16,32,64,128,256,400,800,1600,2000,2500,3000,3500,4000,4500,5000,5500,8000,16000,32000 };
    Double_t Total_Counts_5[] = {100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000};
    Double_t Primary_Counts_5[] = {0,0,0,0,15,34,24,32,27,26,37,38,40,49,40,42,45,41,48,42,57,30};
    Double_t DeltaElectron_Counts_5[] = {0,0,0,0,0,0,0,24,72,157,205,241,284,278,302,318,312,327,315,364,422,410};
    Double_t GammaInvolved_Counts_5[] = {0,0,5,9,40,95,139,236,196,210,269,270,284,273,310,303,296,274,324,336,372,439};
    Double_t NeutronInelastic_Counts_5[]={0,0,0,0,0,0,3,11,4,7,15,14,10,15,15,15,18,21,13,22,16,28};
    Double_t ProtonInelastic_Counts_5[] ={0,0,0,0,3,8,21,23,29,48,62,57,63,61,49,52,57,60,66,51,66,57};
    Double_t HadronElastic_Counts_5[] = {0,0,0,0,0,1,5,11,5,13,11,11,22,12,8,21,15,12,18,14,12,13};
    Double_t Others_5[] = {0,0,0,0,0,0,1,0,0,2,1,2,0,5,2,4,4,3,5,9,11,9};
    Double_t InRange_5[] = {0,0,5,9,58,134,166,246,248,323,437,459,499,488,519,523,538,490,538,577,637,678};

//proton iso
   Double_t Energy_7[] = {  2,4,8,16,32,64,128,256,512,1024,1500,2000,2500,3000,3500,4000,4500,5000,5500,6000,6500,7000,8000,16000,32000 };
    Double_t Total_Counts_7[] = {10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000};
    Double_t Primary_Counts_7[] = {0,685,5410,2917,746,1375,2252,4489,11844,15570,16412,16592,16609,16743,16825,16579,16652,16408,16560,16403,16504,16508,16342,15985,15850};
    Double_t DeltaElectron_Counts_7[] = {0,0,0,0,0,0,0,45,968,1338,1540,1646,1851,1826,2028,2000,2112,2208,2306,2329,2326,2387,2411,2659,2852};
    Double_t GammaInvolved_Counts_7[] = {0,5,12,59,239,807,1157,1141,1179,1449,1593,1693,1821,1837,1887,2007,2012,2032,2092,2249,2183,2184,2296,2631,2690};
    Double_t NeutronInelastic_Counts_7[]={0,0,0,0,1,8,35,40,45,52,66,75,73,88,78,96,104,106,107,134,106,118,109,102,111};
    Double_t ProtonInelastic_Counts_7[] ={0,0,2,1,13,51,136,177,274,416,476,541,541,534,552,561,572,562,535,548,621,583,580,534,507};
    Double_t HadronElastic_Counts_7[] = {0,0,0,0,8,21,92,89,77,81,90,77,104,94,100,110,93,129,119,116,138,119,125,117,124};
    Double_t Others_7[] = {0,0,0,0,0,1,3,2,3,8,12,20,12,29,24,33,40,39,44,47,48,59,42,62,93};
    Double_t InRange_7[] = {0,690,5424,2977,1002,2171,3186,5337,12902,16957,17997,18275,18543,18620,18756,18656,18786,18628,18747,18680,18728,18742,18662,18505,18372};

    //electron front
   Double_t Energy_8[] = {  0.005,0.01,0.02,0.04,0.08,0.16,0.32,0.48,0.64,0.96,1.28,1.92,2.56,5.12,10.24,20.48,40.96,81.92,163.84};
    Double_t Total_Counts_8[] = {100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000,100000};
    Double_t Primary_Counts_8[] = {0,0,0,0,0,493,5761,6892,7370,7408,7711,8204,8501,2839,1664,1129,827,682,589};
    Double_t GammaInvolved_Counts_8[] = {0,0,0,0,5,24,35,44,64,116,199,317,420,780,1101,1213,1211,1420,1578};
    Double_t Others_8[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0};
    Double_t InRange_8[] = {0,0,0,0,5,517,5796,6936,7434,7524,7910,8521,8921,3414,2018,1408,1317,1426,1490};

   //electron back
   Double_t Energy_9[] = { 0.036,0.04,0.08,0.16,0.32,0.64,1.28,2.56,5.12,7.0,10.24,20.48,40.96,81.92,163.84};
    Double_t Total_Counts_9[] = {1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,100000,100000,100000,100000,100000};
    Double_t Primary_Counts_9[] = {0,0,0,0,0,0,0,1,2014,6713,927,1163,1135,1047,1027};
    Double_t GammaInvolved_Counts_9[] = {0,0,2,5,29,138,509,1792,6730,11032,1714,2774,2873,2639,2791};
    Double_t Others_9[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    Double_t InRange_9[] = {0,0,2,5,29,138,509,1793,8742,17624,2470,3024,2907,2635,2718};

//electron side
   Double_t Energy_10[] = {0.08,0.16,0.32,0.64,1.28,2.56,5.12,10.24,20.48,40.96,81.92,163.84};
    Double_t Total_Counts_10[] = {1000000,1000000,1000000,1000000,1000000,1000000,100000,100000,100000,100000,100000,100000};
    Double_t Primary_Counts_10[] = {1,2,4,13,46,397,606,784,458,416,525,558};
    Double_t GammaInvolved_Counts_10[] = {1,23,85,308,1091,3226,711,837,834,838,867,956};
    Double_t Others_10[] = {0,0,0,0,0,0,0,0,0,0,0,0};
    Double_t InRange_10[] = {2,25,89,321,1137,3623,1317,1517,1011,826,876,1009};

//electron front
   Double_t Energy_11[] = { 0.16,0.32,0.48,0.64,0.96,1.28,1.92,2.56};
   Double_t Peak_11[] = {2.46830e-02,2.57475e-01,4.31018e-01,5.95867e-01,9.20843e-01,1.24148e+00,1.88298e+00,2.52375e+00};
 
//electron iso
   Double_t Energy_12[] = {0.04,0.08,0.16,0.32,0.48,0.64,1,1.5,2.0,2.5,3.0,3.5,4.0,4.5,5.0,5.5,6.0,6.5,7.0,7.5,8.0,8.5,9.0,10,20,40,80,160};
   Double_t Total_Counts_12[] = {1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000};
   Double_t Primary_Counts_12[] = {1,0,26,468,515,575,566,591,613,687,721,378,417,431,419,468,462,495,509,552,537,565,580,531,498,418,459,541};
   Double_t GammaInvolved_Counts_12[] = {0,0,0,8,14,13,28,60,101,151,206,216,297,320,383,420,511,524,540,563,599,617,662,655,861,856,807,758};
   Double_t Others_12[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
   Double_t InRange_12[] = {1,0,26,476,529,588,594,651,714,838,927,585,707,736,785,872,945,980,1009,1067,1069,1112,1163,1087,1008,882,746,764};

//SPENVIS proton
   Double_t Year_1[] = {1980,1981,1982,1983,1984,1985,1986,1987,1988,1989,1990,1991,1992,1993,1994,1995,1996,1997,1998,1999,2000};
   Double_t GCR_Counts_per_2_Days_1[] = {7.563113E+04,7.499921E+04,8.176083E+04,9.816570E+04,1.473811E+05,1.746587E+05,2.109176E+05,2.154885E+05,2.010592E+05,2.065443E+05,1.299858E+05,8.002820E+04,9.201004E+04,8.789096E+04,1.279730E+05,1.746372E+05,2.044989E+05,2.331859E+05,2.184635E+05,1.602600E+05,1.197454E+05};
   Double_t Trapped_Counts_per_2_Days_1[] = {1.339346E+08,1.286830E+08,1.355677E+08,1.445241E+08,1.549818E+08,1.465976E+08,1.560930E+08,1.609641E+08,1.642126E+08,1.614757E+08,1.646844E+08,1.650165E+08,1.659014E+08,1.655245E+08,1.654781E+08,1.650189E+08,1.659794E+08,1.651414E+08,1.661211E+08,1.670591E+08,1.629427E+08};
   Double_t Year_2[] = {1965,1966,1967,1968,1969,1970,1971,1972,1973,1974,1975};
   Double_t Trapped_Counts_per_2_Days_2[] = {1.478869E+08,1.433527E+08,1.409920E+08,1.398616E+08,1.404234E+08,1.397873E+08,1.354427E+08,1.333638E+08,1.348033E+08,1.326657E+08,1.312555E+08};
//GCR
   TString particle_13[] = {"proton","alpha","C12","O16","e-","e+","gamma"};
   Double_t Primary_Counts_13[] = {1492,26,0,0,4,0,12346};
   Double_t DeltaElectron_Counts_13[] = {210,13,1,2,18,1,0};
   Double_t GammaInvolved_Counts_13[] = {212,77,6,11,21,3,287};
   Double_t NeutronInelastic_Counts_13[]={12,6,0,0,0,0,0};
   Double_t ProtonInelastic_Counts_13[] ={50,2,0,0,0,0,0};
   Double_t HadronElastic_Counts_13[] = {12,2,0,0,0,0,0};
   Double_t Others_13[] = {5,32,4,4,0,0,0};
   Double_t InRange_13[] = {1641,110,7,14,23,1,12632};
   Double_t Total_13[] = {1393740,180560,5080,4820,32690,3270,232361500};

   // auto gr1 = new TGraph( 7,particle_13, Total_13 );
   // gr1->SetName("gr1");
   // gr1->SetTitle("Total Counts of Different Components");
   // // gr1->SetMarkerStyle(21);
   // // gr1->SetLineColor(2);
   // gr1->Draw("AB");



   //  TF1 *lin = new TF1("lin",the_lin,0,3,0);
   //  auto c1 = new TCanvas("c1","Delta E - E Plot @ High Energy");
   //  auto gr = new TGraphErrors(8,Energy_11,Peak_11,nullptr,nullptr);
   //  gr->SetTitle("Delta E - E Plot (electron, front)");
   //  gr->GetXaxis()->SetTitle("E/MeV");
   //  gr->GetYaxis()->SetTitle("Delta E/MeV");
   //  gr->SetMinimum(0);
   //  cout<<gr->GetYaxis()->GetXmin()<<endl;
   //  gr->Draw("ALP*");
   //      lin->Draw("Same");
   //  c1->Update();

   // int size = 21;
   // Double_t GCR_Counts_per_Second_1[21];
   // Double_t Trapped_Counts_per_Second_1[21];
   // for(int i = 0 ; i<size ; i++){
   //    GCR_Counts_per_Second_1[i] = GCR_Counts_per_2_Days_1[i]/172800;
   //    Trapped_Counts_per_Second_1[i] = Trapped_Counts_per_2_Days_1[i]/172800;
   // }

   // auto c1 = new TCanvas("c1","c1");
   // auto gr1 = new TGraphErrors(size,Year_1,GCR_Counts_per_Second_1,nullptr,nullptr);
   // auto gr2 = new TGraphErrors(size,Year_1,Trapped_Counts_per_Second_1,nullptr,nullptr);
   // gr1->SetTitle("GCR Proton Count Rate On Jan. 1st");
   // gr1->GetXaxis()->SetTitle("Year");
   // gr1->GetYaxis()->SetTitle("cm^-2 s^-1");
   // gr1->SetLineColor(2);
   // gr1->SetMarkerStyle(21);
   // gr2->SetTitle("Trapped Proton Count Rate On Jan. 1st");
   // gr2->GetXaxis()->SetTitle("Year");
   // gr2->GetYaxis()->SetTitle("cm^-2 s^-1");
   // gr2->SetMarkerStyle(22);
   // gr2->SetLineColor(3);
   // gr1->Draw("ALP");
   // gr2->Draw("ALP");



int size = 21;
    for(int i = 0; i<size; i++){
      //   Detected_5[i] = Detected_5[i]/Total_Counts_5[i];
      //   Full_Energy_5[i] = Full_Energy_5[i]/Total_Counts_5[i];
        Primary_Counts[i] = Primary_Counts[i]/Total_Counts[i];
        DeltaElectron_Counts[i] = DeltaElectron_Counts[i]/Total_Counts[i];
        GammaInvolved_Counts[i] = GammaInvolved_Counts[i]/Total_Counts[i];
        NeutronInelastic_Counts[i] = NeutronInelastic_Counts[i]/Total_Counts[i];
        ProtonInelastic_Counts[i] = ProtonInelastic_Counts[i]/Total_Counts[i];
        HadronElastic_Counts[i] = HadronElastic_Counts[i]/Total_Counts[i];
        Others[i] = Others[i]/Total_Counts[i];
        InRange[i] = InRange[i]/Total_Counts[i];
    }

    
   auto c3 = new TCanvas("c3","c3",700, 400);
   auto mg = new TMultiGraph("mg","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
   auto gr1 = new TGraph( size,Energy, Primary_Counts);
   gr1->SetName("Primary_Counts");
   gr1->SetTitle("Primary");
   gr1->SetMarkerStyle(21);
   gr1->SetDrawOption("AP");
   gr1->SetLineColor(2);
   // gr1->SetLineWidth(4);
   // gr1->SetFillStyle(0);
   auto gr2 = new TGraph( size,Energy, DeltaElectron_Counts);
   gr2->SetName("DeltaElectron_Counts");
   gr2->SetTitle("Delta Electron");
   gr2->SetMarkerStyle(22);
   gr2->SetMarkerColor(2);
   gr2->SetDrawOption("P");
   gr2->SetLineColor(3);
   // gr2->SetLineWidth(4);
   // gr2->SetFillStyle(0);
   auto gr3 = new TGraph( size,Energy, GammaInvolved_Counts );
   gr3->SetName("GammaInvolved_Counts");
   gr3->SetTitle("Gamma Involved");
   gr3->SetMarkerStyle(23);
   gr3->SetLineColor(4);
   // gr3->SetLineWidth(4);
   // gr3->SetFillStyle(0);
      auto gr4 = new TGraph( size,Energy, NeutronInelastic_Counts);
   gr4->SetName("NeutronInelastic_Counts");
   gr4->SetTitle("Neutron Inelastic");
   gr4->SetMarkerStyle(24);
   gr4->SetLineColor(5);
// //    gr4->SetLineWidth(4);
// //    gr4->SetFillStyle(0);
      auto gr5 = new TGraph( size,Energy, ProtonInelastic_Counts );
   gr5->SetName("ProtonInelastic_Counts");
   gr5->SetTitle("Proton Inelastic");
   gr5->SetMarkerStyle(25);
   gr5->SetLineColor(6);
// //    gr5->SetLineWidth(4);
// //    gr5->SetFillStyle(0);
      auto gr6 = new TGraph( size,Energy, HadronElastic_Counts );
   gr6->SetName("HadronElastic_Counts");
   gr6->SetTitle("Hadron Elastic");
   gr6->SetMarkerStyle(26);
   gr6->SetLineColor(7);
   // gr6->SetLineWidth(4);
   // gr6->SetFillStyle(0);
      auto gr7 = new TGraph( size,Energy, Others);
   gr7->SetName("Others");
   gr7->SetTitle("Others");
   gr7->SetMarkerStyle(27);
   gr7->SetLineColor(8);
//    gr7->SetLineWidth(4);
//    gr7->SetFillStyle(0);
      auto gr8 = new TGraph( size,Energy, InRange);
   gr8->SetName("InRange");
   gr8->SetTitle("Events Detected");
   gr8->SetMarkerStyle(28);
   gr8->SetLineColor(9);
//    gr8->SetLineWidth(4);
//    gr8->SetFillStyle(0);

   mg->Add( gr1 );
   mg->Add( gr2 );
   mg->Add( gr3 );
   mg->Add( gr4 );
   mg->Add( gr5 );
   mg->Add( gr6 );
   mg->Add( gr7 );
   mg->Add( gr8 );
    mg->GetXaxis()->SetTitle("E(MeV)");
    mg->GetYaxis()->SetTitle("Process Involved Tracks/Total Events");
   mg->Draw("ALP");
   c3->SetLogx();
   c3->SetLeftMargin(1e-1);
   c3->BuildLegend();



}