{
   gStyle->SetOptStat(0);
   auto c1 = new TCanvas();

   auto h1 = new TH1D("h1", "", 100, -5, 5);
   auto h2 = new TH1D("h2", "", 100, -5, 5);
   auto h3 = new TH1D("h3", "", 100, -5, 5);

   h1->Sumw2();
   h2->Sumw2();
   h3->Sumw2();

   h1->FillRandom("gaus", 5000);
   h2->FillRandom("gaus", 3000);
   h3->FillRandom("gaus", 2000);

   h3->Scale(4.);

   h1->SetFillStyle(1001);
   h2->SetFillStyle(1001);
   h1->SetFillColor(2);
   h2->SetFillColor(3);

   auto stack = new THStack();
   stack->Add(h1);
   stack->Add(h2);

   /*stack->Draw("A");*/
   /*h3->Draw("same+E");*/

   auto rp = new TRatioPlot(stack, h3, "divsym"); 
   c1->SetTicks(1, 1);
   rp->Draw();

   /*rp->GetUpperPad()->cd();*/
   /*stack->Draw("hist");*/
   /*h3->Draw("same");*/

   c1->Update();
   c1->SaveAs("run/stack.png");
}
