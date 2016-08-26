{
   gStyle->SetOptStat(0);
   
   auto c1 = new TCanvas("c1", "fit residual simple");
   gPad->SetFrameFillStyle(0);
   c1->SetLogy();
   auto h1 = new TH1D("h1", "h1", 50, -5, 5);
   h1->FillRandom("gaus", 2000);
   h1->Fit("gaus");
   h1->Sumw2(); 

   c1->Clear();

   h1->SetMinimum(0.1);

   auto rp1 = new TRatioPlot(h1);
   rp1->Draw();
   rp1->GetLowerRefGraph()->SetMinimum(-2);
   rp1->GetLowerRefGraph()->SetMaximum(2);
   c1->Update();
   c1->SaveAs("run/fitres_logy.png");
}
