update `quest_template` set `RewRepFaction1` = 
case `RewRepFaction1`
  when    0 then   0
  when   11 then  72
  when   12 then  72
  when   23 then  54
  when   29 then  76
  when   55 then  47
  when   64 then  54
  when   68 then  68
  when   69 then 470
  when   79 then  69
  when   80 then  69
  when   83 then  67
  when   85 then  76
  when  104 then  81
  when  105 then  81
  when  118 then  68
  when  119 then  87
  when  120 then  21
  when  121 then  21
  when  126 then 530
  when  132 then  92
  when  133 then  93
  when  414 then 576
  when  471 then 349
  when  474 then 369
  when  534 then 469
  when  635 then 609
  when  694 then 471
  when  776 then 910
  when  794 then 529
  when  854 then 577
  when  874 then 589
  when  994 then 609
  when 1214 then 729
  when 1216 then 730
  when 1514 then 890
  when 1515 then 889
  when 1555 then 909
  when 1574 then 270
  when 1577 then 509
  when 1598 then 510
  when 1601 then 910
  when 1635 then 169

  else `RewRepFaction1`*'-1'
end;

update `quest_template` set `RewRepFaction2` = 
case `RewRepFaction2`
  when    0 then   0
  when   11 then  72
  when   12 then  72
  when   23 then  54
  when   29 then  76
  when   55 then  47
  when   64 then  54
  when   68 then  68
  when   69 then 470
  when   79 then  69
  when   80 then  69
  when   83 then  67
  when   85 then  76
  when  104 then  81
  when  105 then  81
  when  118 then  68
  when  119 then  87
  when  120 then  21
  when  121 then  21
  when  126 then 530
  when  132 then  92
  when  133 then  93
  when  414 then 576
  when  471 then 349
  when  474 then 369
  when  534 then 469
  when  635 then 609
  when  694 then 471
  when  776 then 910
  when  794 then 529
  when  854 then 577
  when  874 then 589
  when  994 then 609
  when 1214 then 729
  when 1216 then 730
  when 1514 then 890
  when 1515 then 889
  when 1555 then 909
  when 1574 then 270
  when 1577 then 509
  when 1598 then 510
  when 1601 then 910
  when 1635 then 169

  else `RewRepFaction2`*'-1'
end;

