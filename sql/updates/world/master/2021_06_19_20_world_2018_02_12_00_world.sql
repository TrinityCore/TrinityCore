-- SAI target fix for Territorial Trespass (13051)
update `smart_scripts` set `target_type`=23 where (`source_type`=0 and `entryorguid`=30461 and `id`=2) or (`source_type`=9 and `entryorguid`=3046200 and `id` in (1,4));
