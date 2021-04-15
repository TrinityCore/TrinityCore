UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`unit_flags`=`unit_flags`|16777216,`spell1`=50978,`spell2`=50980,`spell3`=50985,`spell4`=50983,`spell5`=54166,`VehicleId`=111,`Health_mod`=18,`Mana_mod`=12,`questItem1`=0,`AIName`='',`ScriptName`='' WHERE `entry`=28222;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=28222;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(28222,52082,12546,1,12546,1,0,0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=16 AND `SourceEntry`=28222;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(16,0,28222,0,23,4282,0,0,0,'','Ride vehicle only in Area');
