SET @BUFFNPC := 190005;
SET @GOPTION := 50030;

DELETE FROM gossip_menu_option WHERE menu_id = @GOPTION;
DELETE FROM smart_scripts WHERE entryorguid = @BUFFNPC;
DELETE FROM creature_template WHERE entry = @BUFFNPC;

INSERT INTO creature_template (entry, modelid1, name, subname, IconName, gossip_menu_id, minlevel, maxlevel, HealthModifier, ManaModifier, ArmorModifier, faction, npcflag, speed_walk, speed_run, scale, rank, DamageModifier, unit_class, unit_flags, type, type_flags, InhabitType, RegenHealth, flags_extra, AiName) VALUES
(@BUFFNPC, '21572', "BUFFER", "Buff NPC", 'Directions', '50000', 71, 71, 1.56, 1.56, 1.56, 35, 3, 1, 1.14286, 1, 1, 1, 1, 2, 7, 138936390, 3, 1, 2, 'SmartAI');

SET @GID := IFNULL((SELECT id FROM gossip_menu_option WHERE menu_id = @GOPTION ORDER BY id DESC LIMIT 1), 0)+1;
INSERT INTO gossip_menu_option (menu_id, id, option_icon, option_text, option_id, npc_option_npcflag, action_menu_id, action_poi_id, box_coded, box_money, box_text) VALUES
(@GOPTION, @GID, 2, 'Power Word: Fortitude', 1, 1, @GOPTION, 0, 0, 0, NULL), 
(@GOPTION, @GID+1, 2, 'Divine Spirit', 1, 1, @GOPTION, 0, 0, 0, NULL), 
(@GOPTION, @GID+2, 2, 'Shadow Protection', 1, 1, @GOPTION, 0, 0, 0, NULL), 
(@GOPTION, @GID+3, 2, 'Arcane Intellect', 1, 1, @GOPTION, 0, 0, 0, NULL),
(@GOPTION, @GID+4, 2, 'Dalaran Inellect', 1, 1, @GOPTION, 0, 0, 0, NULL), 
(@GOPTION, @GID+5, 2, 'Blessing of Kings', 1, 1, @GOPTION, 0, 0, 0, NULL), 
(@GOPTION, @GID+6, 2, 'Blessing of Might', 1, 1, @GOPTION, 0, 0, 0, NULL), 
(@GOPTION, @GID+7, 2, 'Blessing of Wisdom', 1, 1, @GOPTION, 0, 0, 0, NULL), 
(@GOPTION, @GID+8, 2, 'Blessing of Santuary', 1, 1, @GOPTION, 0, 0, 0, NULL), 
(@GOPTION, @GID+9, 2, 'Mark of the Wild', 1, 1, @GOPTION, 0, 0, 0, NULL); 

SET @SID := IFNULL((SELECT id FROM smart_scripts WHERE entryorguid = @BUFFNPC ORDER BY id DESC LIMIT 1), 0)+1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@BUFFNPC, 0, @SID, 0, 62, 0, 100, 0, @GOPTION, @GID, 0, 0, 85, 48161, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, ''),
(@BUFFNPC, 0, @SID+1, 0, 62, 0, 100, 0, @GOPTION, @GID+1, 0, 0, 85, 48073, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, ''),
(@BUFFNPC, 0, @SID+2, 0, 62, 0, 100, 0, @GOPTION, @GID+2, 0, 0, 85, 48169, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, ''),
(@BUFFNPC, 0, @SID+3, 0, 62, 0, 100, 0, @GOPTION, @GID+3, 0, 0, 85, 42995, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, ''),
(@BUFFNPC, 0, @SID+4, 0, 62, 0, 100, 0, @GOPTION, @GID+4, 0, 0, 85, 61024, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, ''),
(@BUFFNPC, 0, @SID+5, 0, 62, 0, 100, 0, @GOPTION, @GID+5, 0, 0, 85, 25898, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, ''),
(@BUFFNPC, 0, @SID+6, 0, 62, 0, 100, 0, @GOPTION, @GID+6, 0, 0, 85, 48934, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, ''),
(@BUFFNPC, 0, @SID+7, 0, 62, 0, 100, 0, @GOPTION, @GID+7, 0, 0, 85, 48938, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, ''),
(@BUFFNPC, 0, @SID+8, 0, 62, 0, 100, 0, @GOPTION, @GID+8, 0, 0, 85, 25899, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, ''),
(@BUFFNPC, 0, @SID+9, 0, 62, 0, 100, 0, @GOPTION, @GID+9, 0, 0, 85, 48469, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '');

UPDATE creature_template SET gossip_menu_id = @GOPTION, npcflag = npcflag|1, AIName = 'SmartAI' WHERE Entry = @BUFFNPC;

REPLACE INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
('15121977', '190005', '1', '1', '1', '0', '0', '1594.71', '-4404.57', '7.03082', '2.01403', '300', '0', '0', '6495', '0', '0', '0', '0', '0'),
('15121978', '190005', '0', '1', '1', '0', '0', '-8822.33', '630.718', '94.8776', '3.8272', '300', '0', '0', '6495', '0', '0', '0', '0', '0');
