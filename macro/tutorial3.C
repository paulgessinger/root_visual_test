{
  gROOT->SetBatch();
  gROOT->ProcessLine(".x ~/Code/root/tutorials/hist/ratioplot3.C");
  c1->SaveAs("run/tutorial3.png");
}

