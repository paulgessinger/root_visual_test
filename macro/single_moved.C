{
   gStyle->SetOptStat(0);
   
   auto c1 = new TCanvas("c1", "fit residual simple");
   auto h1 = new TH1D("h1", "h1", 50, -5, 5);
   h1->FillRandom("gaus", 2000);
   h1->Fit("gaus");
   h1->Sumw2(); 
 
   c1->Clear();
   
   auto pad = new TPad("pad", "", 0.3, 0.3, 1.0, 1.0);
   pad->Draw();
   pad->cd();
   auto rp1 = new TRatioPlot(h1);

   rp1->Draw();
   c1->Update();
   c1->SaveAs("run/single_moved.png");
}
