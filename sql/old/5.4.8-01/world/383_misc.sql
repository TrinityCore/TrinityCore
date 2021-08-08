update spell_bonus_data set dot_bonus=0.02345 where entry=114163;
update spell_proc_event set SchoolMask=1, procFlags=0, procEx=1027, CustomChance=0 where entry=20154;
replace into spell_linked_spell values (107570, 132169, 0, 'Storm Bolt(stun)');
replace into spell_bonus_data values (46968, 0, 0, 0.742, 0, 'Shockwave(custom)');
