DELETE FROM gameobject WHERE guid=99998;
INSERT INTO `gameobject` (guid, id, map, spawnMask, phaseMask, position_x, position_y, position_z, spawntimesecs, State) VALUES 
(99998, 180673, 1, 1, 1, 6723.67, -5271.68, 778, 180, 1);

set @Xandivious:=15623;

Delete from creature_loot_template where entry =@Xandivious and item=21145;

Update creature_template set `AIName`='SmartAI' where entry in (@Xandivious);

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Xandivious AND `source_type` = 0;
Insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) values

(@Xandivious, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 25818, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, ' Xandivious - On reset - cast Aura of Rot'),
(@Xandivious, 0, 1, 0, 0, 0, 100, 0, 3000, 3000, 15000, 15000, 11, 11980, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Xandivious - IC - cast Curse of Weakness'),
(@Xandivious, 0, 2, 0, 0, 0, 100, 0, 5000, 5000, 15000, 15000, 11, 11639, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Xandivious - IC - cast Shadow Word: Pain'),
(@Xandivious, 0, 3, 0, 0, 0, 100, 0, 7000, 7000, 10000, 10000, 11, 16046, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Xandivious - IC - cast Blast Wave'),
(@Xandivious, 0, 4, 0, 2, 0, 100, 1, 0, 50, 0, 0, 11, 8599, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Xandivious - HP under 50% - Enrage'),
(@Xandivious, 0, 5, 0, 6, 0, 100, 0, 0, 0, 0, 0, 85, 25791, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Xandivious - On Death - invoker_Cast Xandivious Demon Bag');
