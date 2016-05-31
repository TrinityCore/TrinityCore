-- Addon data based on sniff fixed by Vincent-Michael
DELETE FROM `creature_template_addon` WHERE `entry` IN (27692,27755,27756);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(27692,0,0,0x3000000,0x1,0,'50296 50325'), -- Emerald Drake
(27755,0,0,0x3000000,0x1,0,'50296 50325'), -- Amber Drake
(27756,0,0,0x3000000,0x1,0,'50296 50248 50325'); -- Ruby Drake // Evasive aura should be here from the start
-- Change InhabitType to prevent drakes falling on summon
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (27692,27755,27756);
-- Change script name for gossip npcs and drakes and set npc_flag to 0, since only after Ist boss is dead, they should acquire gossip flag
UPDATE `creature_template` SET `npcflag`=2,`ScriptName`='npc_verdisa_beglaristrasz_eternos' WHERE `entry` IN (27657,27658,27659);
UPDATE `creature_template` SET `spell2`=50240,`spell3`=50253,`spell4`=0  WHERE `entry`=27756; -- Remove Evasive Aura and set Evasive Manouvres since it is an aura always applied, also set Martyr as 3rd
UPDATE `creature_template` SET `spell6`=53389,`ScriptName`='npc_ruby_emerald_amber_drake' WHERE `entry` IN (27692,27755,27756); -- Add GPS spell for all drakes and script names for drakes
-- Add spell_script name for Call Ruby/Emerald/Amber Drake spells
DELETE FROM `spell_script_names` WHERE `spell_id` IN (49462,49345,49461);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(49462,'spell_call_ruby_emerald_amber_drake'), -- Ruby
(49345,'spell_call_ruby_emerald_amber_drake'), -- Emerald
(49461,'spell_call_ruby_emerald_amber_drake'); -- Amber
-- Remove wrong use of npc_spellclick_spell, the drake should auto do all on summon
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (27692,27755,27756);
-- Add conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (49464,49346,49460,66667,49838);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (49840,49592,50328,50341,50232);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1|4,49464,0,0,33,0,1,5,0,0,0,'','Ruby Drake Saddle control vehicle aura can hit only created unit'),
(13,1|4,49346,0,0,33,0,1,5,0,0,0,'','Emerald Drake Saddle control vehicle aura can hit only created unit'),
(13,1|4,49460,0,0,33,0,1,5,0,0,0,'','Amber Drake Saddle control vehicle aura can hit only created unit'),
(13,1|2|4,66667,0,0,33,1,0,0,0,0,0,'','Gear scaling for Oculus drakes can only be casted on self'),
(17,0,49840,0,1,31,1,3,28236,0,0,0,'','Shock Lance target can be Azure Ring Captain'),
(17,0,49840,0,2,31,1,3,27638,0,0,0,'','Shock Lance target can be Azure Ring Guardian'),
(17,0,49840,0,3,31,1,3,28276,0,0,0,'','Shock Lance target can be Greater Lay Whelp'),
(17,0,49840,0,4,31,1,3,27656,0,0,0,'','Shock Lance target can be Eregos'),
(13,1,49838,0,1,31,0,3,28236,0,0,0,'','Stop Time can hit Azure Ring Captain'),
(13,1,49838,0,2,31,0,3,27638,0,0,0,'','Stop Time can hit Azure Ring Guardian'),
(13,1,49838,0,3,31,0,3,28276,0,0,0,'','Stop Time can hit Greater Lay Whelp'),
(13,1,49838,0,4,31,0,3,27656,0,0,0,'','Stop Time can hit Eregos'),
(17,0,49592,0,1,31,1,3,28236,0,0,0,'','Temporal Rift target can be Azure Ring Captain'),
(17,0,49592,0,2,31,1,3,27638,0,0,0,'','Temporal Rift target can be Azure Ring Guardian'),
(17,0,49592,0,3,31,1,3,28276,0,0,0,'','Temporal Rift target can be Greater Lay Whelp'),
(17,0,49592,0,4,31,1,3,27656,0,0,0,'','Temporal Rift target can be Eregos'),
(17,0,50328,0,1,31,1,3,28236,0,0,0,'','Leeching Poison target can be Azure Ring Captain'),
(17,0,50328,0,2,31,1,3,27638,0,0,0,'','Leeching Poison target can be Azure Ring Guardian'),
(17,0,50328,0,3,31,1,3,28276,0,0,0,'','Leeching Poison target can be Greater Lay Whelp'),
(17,0,50328,0,4,31,1,3,27656,0,0,0,'','Leeching Poison target can be Eregos'),
(17,0,50341,0,1,31,1,3,28236,0,0,0,'','Touch the Nightmare target can be Azure Ring Captain'),
(17,0,50341,0,2,31,1,3,27638,0,0,0,'','Touch the Nightmare target can be Azure Ring Guardian'),
(17,0,50341,0,3,31,1,3,28276,0,0,0,'','Touch the Nightmare target can be Greater Lay Whelp'),
(17,0,50341,0,4,31,1,3,27656,0,0,0,'','Touch the Nightmare target can be Eregos'),
(17,0,50232,0,1,31,1,3,28236,0,0,0,'','Searing Wrath target can be Azure Ring Captain'),
(17,0,50232,0,2,31,1,3,27638,0,0,0,'','Searing Wrath target can be Azure Ring Guardian'),
(17,0,50232,0,3,31,1,3,28276,0,0,0,'','Searing Wrath target can be Greater Lay Whelp'),
(17,0,50232,0,4,31,1,3,27656,0,0,0,'','Searing Wrath target can be Eregos');
-- Add text for Belgaristrasz
SET @Belgaristrasz := 27658;
DELETE FROM `creature_text` WHERE `entry`=@Belgaristrasz;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Belgaristrasz,0,0,'Thank you for freeing us, mortals. Beware, the blue flight is alerted to your presence. Even now, Malygos sends Varos Cloudstrider and his ring guardians to defend the Oculus. You will need our help to stand a chance.',12,0,100,1,3500,0,'Belgaristrasz - On freed');
-- Add text for Ruby, Amber and Emerald drakes
SET @Ruby :=    27756;
SET @Emerald := 27692;
SET @Amber :=   27755;
DELETE FROM `creature_text` WHERE `entry` IN (@Ruby,@Emerald,@Amber);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Ruby,0,0,'Ruby Drake flies away.',16,0,100,1,0,2858,'Ruby - On take off'),
(@Ruby,1,0,'Welcome Friend. Keep your head down and hold on tight!',15,0,100,1,0,0,'Ruby - On welcome'),
(@Ruby,2,0,'Use Searing Wrath to damage enemies and Evasive Maneuvers if I start taking damage. Remember I need to build up Evasive Charges by taking damage to perform Evasive Maneuvers!',15,0,100,1,0,0,'Ruby - On explaining abilities'),
(@Ruby,3,0,'Now that I am at my full power I can perform Martyr. You can use it to protect other drakes, but I will take lots of damage, so make sure you''re using Evasive Maneuvers too!',15,0,100,1,0,0,'Ruby - On ultimate ability unlocked'),
(@Ruby,4,0,'I''m badly injured! I can''t take much more of this!',15,0,100,1,0,0,'Ruby - On below 40%'),
(@Emerald,0,0,'Emerald Drake flies away.',16,0,100,1,0,2858,'Emerald - On take off'),
(@Emerald,1,0,'Welcome Friend. Keep your head down and hold on tight!',15,0,100,1,0,0,'Emerald - On welcome'),
(@Emerald,2,0,'Use Leeching Poison to damage enemies and keep me healed. Touch the Nightmare is very powerful, but it hurts me, so only use it when I have a lot of health!',15,0,100,1,0,0,'Emerald - On explaining abilities'),
(@Emerald,3,0,'Now that I am at my full power I can perform Dream Funnel. You can use it to heal other drakes, but it drains my health, so make sure you''re using Leeching Poison too!',15,0,100,1,0,0,'Emerald - On ultimate ability unlocked'),
(@Emerald,4,0,'I''m badly injured! I can''t take much more of this!',15,0,100,1,0,0,'Emerald - On below 40%'),
(@Amber,0,0,'Amber Drake flies away.',16,0,100,1,0,2858,'Amber - On take off'),
(@Amber,1,0,'Welcome Friend. Keep your head down and hold on tight!',15,0,100,1,0,0,'Amber - On welcome'),
(@Amber,2,0,'Use Shock Lance to damage enemies. If we get in trouble, Stop Time to freeze all enemies in place, then hit them with Shock Lance for massive damage!',15,0,100,1,0,0,'Amber - On explaining abilities'),
(@Amber,3,0,'Now that I am at my full power I can perform Temporal Rift. You can use it to make enemies take extra damage and to get Shock Charges. Save up Shock Charges and then Shock Lance for huge damage!',15,0,100,1,0,0,'Amber - On ultimate ability unlocked'),
(@Amber,4,0,'I''m badly injured! I can''t take much more of this!',15,0,100,1,0,0,'Amber - On below 40%');
-- Fix Oculus phasing db side, all listed get changed only on specific isntance data
UPDATE `creature` SET `phaseMask`=2 WHERE `id` IN (27447,27655,28276,27656);
