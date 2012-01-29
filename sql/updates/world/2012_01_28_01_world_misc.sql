DELETE FROM `spell_script_names` WHERE `spell_id` IN (26374);
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES
(26374,'spell_gen_elune_candle');

-- Set Gigant Spotlight as not selectable
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=15902;

DELETE FROM `creature_template_addon` WHERE (`entry`IN(15902,15466));
INSERT INTO `creature_template_addon`(`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(15466,0,0,0,0,0,17327), -- Add spirit particles to Omen minions
(15902,0,0,0,0,0,50236); -- Add Spotlight aura to Gigant Spotlight (ummoned by 26392 on Omen's death)

UPDATE `creature_template` SET `ScriptName`='npc_giant_spotlight' WHERE `entry`=15902;
UPDATE `creature_template` SET `RegenHealth`=0,`ScriptName`='npc_omen' WHERE `entry`=15467;
UPDATE `creature_template` SET `ScriptName`='npc_firework',`AIName`='',`faction_A`=35,`faction_H`=35,`unit_flags`=33555200 WHERE `entry` IN (15879,15880,15881,15882,15883,15884,15885,15886,15887,15888,15889,15890,15872,15873,15874,15875,15876,15877,15911,15912,15913,15914,15915,15916,15918);
-- Cleanup EventAI and SmartAI
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (15879,15880,15881,15882,15883,15884,15885,15886,15887,15888,15889,15890,15872,15873,15874,15875,15876,15877,15911,15912,15913,15914,15915,15916,15918);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (15879,15880,15881,15882,15883,15884,15885,15886,15887,15888,15889,15890,15872,15873,15874,15875,15876,15877,15911,15912,15913,15914,15915,15916,15918);

-- Update al targeting stuff for Fireworks and Rocket clusters
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (26294,26295,26333,26334,26336,26337,26338,26488,26490,26517,26521,26344,26347,26345,26348,26349,26351,26352,26354,26355,26356);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- Targeting Firework Launcher
(13,0,26294,0,18,0,180771,0,0,'',"Small White Rocket target Firework Launcher"),
(13,0,26294,0,18,0,180850,0,0,'',"Small White Rocket target Firework Launcher"),
(13,0,26294,0,18,0,180868,0,0,'',"Small White Rocket target Firework Launcher"),
(13,0,26295,0,18,0,180771,0,0,'',"Small Yellow Rocket target Firework Launcher"),
(13,0,26295,0,18,0,180850,0,0,'',"Small Yellow Rocket target Firework Launcher"),
(13,0,26295,0,18,0,180868,0,0,'',"Small Yellow Rocket target Firework Launcher"),
(13,0,26333,0,18,0,180771,0,0,'',"Large Blue Rocket target Firework Launcher"),
(13,0,26333,0,18,0,180850,0,0,'',"Large Blue Rocket target Firework Launcher"),
(13,0,26333,0,18,0,180868,0,0,'',"Large Blue Rocket target Firework Launcher"),
(13,0,26334,0,18,0,180771,0,0,'',"Large Green Rocket target Firework Launcher"),
(13,0,26334,0,18,0,180850,0,0,'',"Large Green Rocket target Firework Launcher"),
(13,0,26334,0,18,0,180868,0,0,'',"Large Green Rocket target Firework Launcher"),
(13,0,26336,0,18,0,180771,0,0,'',"Large Red Rocket target Firework Launcher"),
(13,0,26336,0,18,0,180850,0,0,'',"Large Red Rocket target Firework Launcher"),
(13,0,26336,0,18,0,180868,0,0,'',"Large Red Rocket target Firework Launcher"),
(13,0,26337,0,18,0,180771,0,0,'',"Large White Rocket target Firework Launcher"),
(13,0,26337,0,18,0,180850,0,0,'',"Large White Rocket target Firework Launcher"),
(13,0,26337,0,18,0,180868,0,0,'',"Large White Rocket target Firework Launcher"),
(13,0,26338,0,18,0,180771,0,0,'',"Large Yellow Rocket target Firework Launcher"),
(13,0,26338,0,18,0,180850,0,0,'',"Large Yellow Rocket target Firework Launcher"),
(13,0,26338,0,18,0,180868,0,0,'',"Large Yellow Rocket target Firework Launcher"),
-- Targeting Cluster Launcher
(13,0,26488,0,18,0,180772,0,0,'',"Large Blue Rocket Cluster target Cluster Launcher"),
(13,0,26488,0,18,0,180859,0,0,'',"Large Blue Rocket Cluster target Cluster Launcher"),
(13,0,26488,0,18,0,180869,0,0,'',"Large Blue Rocket Cluster target Cluster Launcher"),
(13,0,26488,0,18,0,180874,0,0,'',"Large Blue Rocket Cluster target Cluster Launcher"),
(13,0,26490,0,18,0,180772,0,0,'',"Large Green Rocket Cluster target Cluster Launcher"),
(13,0,26490,0,18,0,180859,0,0,'',"Large Green Rocket Cluster target Cluster Launcher"),
(13,0,26490,0,18,0,180869,0,0,'',"Large Green Rocket Cluster target Cluster Launcher"),
(13,0,26490,0,18,0,180874,0,0,'',"Large Green Rocket Cluster target Cluster Launcher"),
(13,0,26517,0,18,0,180772,0,0,'',"Large Red Rocket Cluster target Cluster Launcher"),
(13,0,26517,0,18,0,180859,0,0,'',"Large Red Rocket Cluster target Cluster Launcher"),
(13,0,26517,0,18,0,180869,0,0,'',"Large Red Rocket Cluster target Cluster Launcher"),
(13,0,26517,0,18,0,180874,0,0,'',"Large Red Rocket Cluster target Cluster Launcher"),
(13,0,26521,0,18,0,180772,0,0,'',"Lucky Lunar rocket Cluster target Cluster Launcher"),
(13,0,26521,0,18,0,180859,0,0,'',"Lucky Lunar rocket Cluster target Cluster Launcher"),
(13,0,26521,0,18,0,180869,0,0,'',"Lucky Lunar rocket Cluster target Cluster Launcher"),
(13,0,26521,0,18,0,180874,0,0,'',"Lucky Lunar rocket Cluster target Cluster Launcher"),
-- Targeting Firework Launcher (Again)
(13,0,26347,0,18,0,180771,0,0,'',"Rocket, RED target Firework Launcher"),
(13,0,26347,0,18,0,180850,0,0,'',"Rocket, RED target Firework Launcher"),
(13,0,26347,0,18,0,180868,0,0,'',"Rocket, RED target Firework Launcher"),
(13,0,26344,0,18,0,180771,0,0,'',"Rocket, BLUE target Firework Launcher"),
(13,0,26344,0,18,0,180850,0,0,'',"Rocket, BLUE target Firework Launcher"),
(13,0,26344,0,18,0,180868,0,0,'',"Rocket, BLUE target Firework Launcher"),
(13,0,26345,0,18,0,180771,0,0,'',"Rocket, GREEEN target Firework Launcher"),
(13,0,26345,0,18,0,180850,0,0,'',"Rocket, GREEEN target Firework Launcher"),
(13,0,26345,0,18,0,180868,0,0,'',"Rocket, GREEEN target Firework Launcher"),
(13,0,26348,0,18,0,180771,0,0,'',"Rocket, WHITE target Firework Launcher"),
(13,0,26348,0,18,0,180850,0,0,'',"Rocket, WHITE target Firework Launcher"),
(13,0,26348,0,18,0,180868,0,0,'',"Rocket, WHITE target Firework Launcher"),
(13,0,26349,0,18,0,180771,0,0,'',"Rocket, YELLOW target Firework Launcher"),
(13,0,26349,0,18,0,180850,0,0,'',"Rocket, YELLOW target Firework Launcher"),
(13,0,26349,0,18,0,180868,0,0,'',"Rocket, YELLOW target Firework Launcher"),
(13,0,26351,0,18,0,180771,0,0,'',"Rocket, BLUE BIG target Firework Launcher"),
(13,0,26351,0,18,0,180850,0,0,'',"Rocket, BLUE BIG target Firework Launcher"),
(13,0,26351,0,18,0,180868,0,0,'',"Rocket, BLUE BIG target Firework Launcher"),
(13,0,26352,0,18,0,180771,0,0,'',"Rocket, GREEN BIG target Firework Launcher"),
(13,0,26352,0,18,0,180850,0,0,'',"Rocket, GREEN BIG target Firework Launcher"),
(13,0,26352,0,18,0,180868,0,0,'',"Rocket, GREEN BIG target Firework Launcher"),
(13,0,26354,0,18,0,180771,0,0,'',"Rocket, RED BIG target Firework Launcher"),
(13,0,26354,0,18,0,180850,0,0,'',"Rocket, RED BIG target Firework Launcher"),
(13,0,26354,0,18,0,180868,0,0,'',"Rocket, RED BIG target Firework Launcher"),
(13,0,26355,0,18,0,180771,0,0,'',"Rocket, WHITE BIG target Firework Launcher"),
(13,0,26355,0,18,0,180850,0,0,'',"Rocket, WHITE BIG target Firework Launcher"),
(13,0,26355,0,18,0,180868,0,0,'',"Rocket, WHITE BIG target Firework Launcher"),
(13,0,26356,0,18,0,180771,0,0,'',"Rocket, YELLOW BIG target Firework Launcher"),
(13,0,26356,0,18,0,180850,0,0,'',"Rocket, YELLOW BIG target Firework Launcher"),
(13,0,26356,0,18,0,180868,0,0,'',"Rocket, YELLOW BIG target Firework Launcher");

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=15466;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=15466 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15466,0,0,0,8,0,100,0,26636,0,8000,9000,11,25495,0,0,0,0,0,1,0,0,0,0,0,0,0,"Minion of Omen - Cast Firework Dazzled when hitted by Elune's Candle firework");

-- Cast quest credit spell when getting Elune's Blessing buff
DELETE FROM `spell_scripts` WHERE `id`=26393;
INSERT INTO `spell_scripts`(`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(26393,1,0,15,26394,2,0,0,0,0,0);