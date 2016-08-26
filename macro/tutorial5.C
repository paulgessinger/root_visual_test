{
  gROOT->SetBatch();
  gROOT->ProcessLine(".x ~/Code/root/tutorials/hist/ratioplot5.C");
  c1->SaveAs("run/tutorial5.png");
}

