{
  gROOT->SetBatch();
  gROOT->ProcessLine(".x ~/Code/root/tutorials/hist/ratioplot4.C");
  c1->SaveAs("run/tutorial4.png");
}

