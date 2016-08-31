{
   gROOT->SetBatch();
   gStyle->SetOptStat(0);
   
   auto c1 = new TCanvas("c1", "diff sig");
   auto h2 = new TH1D("h2", "h2", 50, 0, 10);
   auto h3 = new TH1D("h3", "h3", 50, 0, 10);
   auto f1 = new TF1("f1", "exp(- x/[0] )");
   f1->SetParameter(0, 3);
   h2->FillRandom("f1", 1900);
   h3->FillRandom("f1", 2000); 
   h3->Sumw2();
   h3->Scale(1.9 / 2.);
   
   auto rp5 = new TRatioPlot((TH1*)h2->Clone(), (TH1*)h3->Clone(), "divsym nogrid");
   rp5->Draw();


   c1->Update();
   c1->SaveAs("run/diffsig.png");
}
