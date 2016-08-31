{
   gROOT->SetBatch();
   gStyle->SetOptStat(0);
   
   auto c1 = new TCanvas("c1", "fit residual simple");
   gPad->SetFrameFillStyle(0);
   auto h1 = new TH1D("h1", "h1", 50, -5, 5);
   h1->FillRandom("gaus", 5000);
   TFitResultPtr fitres = h1->Fit("gaus", "S");
   h1->Sumw2(); 

   c1->Clear();
 
   auto rp1 = new TRatioPlot(h1, "errfunc");
   rp1->SetGraphDrawOpt("L");
   rp1->Draw("noconfint");
   c1->Update();
   c1->SaveAs("run/fitres_noconfint.png"); 
}
