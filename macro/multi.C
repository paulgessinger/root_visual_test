{
   gStyle->SetOptStat(0);
   
   // one
   auto c1 = new TCanvas("c1", "fit residual simple");
   
   c1->Divide(3, 2);
  
   TVirtualPad *p;
   p = c1->cd(1);
   auto h1 = new TH1D("h1", "h1", 50, -5, 5);
   h1->FillRandom("gaus", 2000);
   h1->Fit("gaus");
   /*h1->Sumw2(); */
  
   
   auto rp1 = new TRatioPlot((TH1*)h1->Clone());

   p->SetTicks(1, 0);

   rp1->Draw();
   rp1->GetLowerRefYaxis()->SetTitle("ratio");
   c1->Update();
   p = c1->cd(2);
   h1->SetBinErrorOption(TH1::EBinErrorOpt::kPoisson);
   auto rp2 = new TRatioPlot((TH1*)h1->Clone(), "errfunc");
   rp2->Draw();
   p->SetTicks(0, 1);
   rp2->GetLowerRefYaxis()->SetTitle("fit errasym");
   c1->Update();

   c1->cd(3);
   gPad->SetFrameFillStyle(0);
   auto h2 = new TH1D("h2", "h2", 50, 0, 10);
   auto h3 = new TH1D("h3", "h3", 50, 0, 10);
   auto f1 = new TF1("f1", "exp(- x/[0] )");
   f1->SetParameter(0, 3);
   h2->FillRandom("f1", 1900);
   h3->FillRandom("f1", 2000); 
   h3->Sumw2();
   h3->Scale(1.9 / 2.);
   auto rp3 = new TRatioPlot((TH1*)h2->Clone(), (TH1*)h3->Clone(), "pois");
   rp3->Draw();
   rp3->GetLowerRefYaxis()->SetTitle("ratio pois");

   c1->cd(4);
   auto rp4 = new TRatioPlot((TH1*)h2->Clone(), (TH1*)h3->Clone(), "divsym");
   rp4->Draw();
   rp4->GetLowerRefYaxis()->SetTitle("ratio divsym");
   
   c1->cd(5);
   auto rp5 = new TRatioPlot((TH1*)h2->Clone(), (TH1*)h3->Clone(), "diff");
   rp5->Draw();
   rp5->GetLowerRefYaxis()->SetTitle("diff");

   c1->cd(6);
   gPad->SetLogy();
   auto rp6 = new TRatioPlot((TH1*)h2->Clone(), (TH1*)h3->Clone(), "diff");
   rp6->Draw();
   rp6->GetLowerRefYaxis()->SetTitle("diff");
   rp6->GetLowerRefGraph()->SetMinimum(-50);
   c1->Update();
   c1->SaveAs("run/multi.png");
}
