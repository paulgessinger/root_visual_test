{

   gROOT->LoadMacro("AtlasStyle.C");
   SetAtlasStyle();

   auto c1 = new TCanvas("c1", "fit residual simple");
   auto h1 = new TH1D("h1", "h1", 50, -5, 5);
   h1->FillRandom("gaus", 2000);
   h1->Fit("gaus");
   h1->Sumw2(); 
 
   c1->Clear();

   auto more = new TGraphAsymmErrors();
   auto rd = new TRandom3();
   for (int i=0;i<=10;++i) {
      more->SetPoint(i, -5 + i, 0);
      more->SetPointError(i, 0, 0, rd->Uniform(), rd->Uniform());
   }

   auto rp1 = new TRatioPlot(h1);
   rp1->Draw();
  
   auto p = rp1->GetLowerPad();
   p->cd();
   p->Clear();
   auto fitres = rp1->GetCalculationOutputGraph();
   more->SetLineColor(kRed);
   more->SetFillColor(kRed);
   more->SetFillStyle(3004);
   more->SetMinimum(-2);
   more->SetMaximum(2);
   more->Draw("IA3");
   fitres->Draw("P+same");
  
   c1->Update();
   c1->SaveAs("run/atlas.png");
}
