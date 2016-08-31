{
   gStyle->SetOptStat(0);
   
   auto c1 = new TCanvas("c1", "fit residual simple");
   gPad->SetFrameFillStyle(0);
   auto h1 = new TH1D("h1", "h1", 50, -5, 5);
   h1->FillRandom("gaus", 5000);
   TFitResultPtr fitres = h1->Fit("gaus", "S");
   
   h1->SetBinErrorOption(TH1::EBinErrorOpt::kPoisson);
   
   c1->Clear();
 
   auto rp1 = new TRatioPlot(h1, "errasym");
   rp1->SetH1DrawOpt("E");
   rp1->SetGraphDrawOpt("L");
   rp1->Draw("noconfint");
   c1->Update();
   c1->SaveAs("run/fitres_asym.png"); 
}
