{
   gStyle->SetOptStat(0);
   
   auto c1 = new TCanvas("c1", "fit residual simple");
   auto h1 = new TH1D("h1", "h1", 50, -5, 5);
   h1->FillRandom("gaus", 2000);
   h1->Fit("gaus");
   h1->Sumw2(); 

   TVirtualPad *p;
   c1->Clear();
   c1->Divide(3, 1);
   p = c1->cd(1);
 
   h1->GetXaxis()->SetTitle("x");
   h1->GetYaxis()->SetTitle("y");
   h1->Draw();

   c1->cd(2);

   auto rp1 = new TRatioPlot(h1);
   rp1->Draw();

   c1->cd(3);

   h1->Draw();


   c1->Update();
   c1->SaveAs("run/single_reuse.png");
}
