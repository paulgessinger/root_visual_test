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
 
   auto rp1 = new TRatioPlot(h1, "errfunc", "", "L");
   rp1->BuildLowerPlot();
   rp1->SetSeparationMargin(0.0);
   rp1->Draw("nohide");
   c1->Update();
   c1->SaveAs("run/nohidelabel.png"); 
}

