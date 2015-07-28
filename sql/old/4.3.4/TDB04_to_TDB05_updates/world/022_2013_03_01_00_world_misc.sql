SET @ELM_BUNNY        :=23837;
SET @SHADOW_CULTIST   :=30835;
SET @VARDMADRA        :=30836;
SET @LK_EYE           :=192861;
SET @CREDIT           :=57884;
SET @SUMMON_CULTIST   :=57885;
SET @GOSSIP_CAST      :=57888;
SET @LK_EYE_CAST      :=57889;
SET @SUMMON_VARDMADRA :=57891;

DELETE FROM `creature_text` WHERE `entry` IN (@ELM_BUNNY,@VARDMADRA,@SHADOW_CULTIST);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@ELM_BUNNY, 0, 0, 'Scrying upon many insignificant situations within Icecrown, you stumble upon something interesting...', 42, 0, 100, 0, 0, 0, 'Eye of Lich King Ambient'),
(@SHADOW_CULTIST, 0, 0, 'My lady.', 12, 0, 100, 0, 0, 0, 'Shadow Cultist'),
(@SHADOW_CULTIST, 1, 0, 'There is word from Jotunheim. The sleep-watchers there believe that they have found someone of significance.', 12, 0, 100, 0, 0, 0, 'Shadow Cultist'),
(@SHADOW_CULTIST, 2, 0, 'The cultist practically sputters.', 16, 0, 100, 0, 0, 0, 'Shadow Cultist'),
(@SHADOW_CULTIST, 3, 0, 'Look like, my lady? A vrykul, I suppose. They did not actually show him to me. Ever since The Shadow Vault....', 12, 0, 100, 0, 0, 0, 'Shadow Cultist'),
(@SHADOW_CULTIST, 4, 0, 'A name? Oh, yes, the name! I believe it was Iskalder.', 12, 0, 100, 0, 0, 0, 'Shadow Cultist'),
(@SHADOW_CULTIST, 5, 0, 'Right away, my lady.', 12, 0, 100, 2, 0, 0, 'Shadow Cultist'),
(@VARDMADRA, 0, 0, 'Report.', 12, 0, 100, 1, 0, 0, 'Vardmadra'),
(@VARDMADRA, 1, 0, 'Describe this vrykul. What does he look like?', 12, 0, 100, 1, 0, 0, 'Vardmadra'),
(@VARDMADRA, 2, 0, 'I am not interested in excuses. Perhaps they gave you a name?', 12, 0, 100, 1, 0, 0, 'Vardmadra'),
(@VARDMADRA, 3, 0, 'Iskalder?! You fool! Have you no idea who that is? He''s only the greatest vrykul warrior who ever lived!', 12, 0, 100, 1, 0, 0, 'Vardmadra'),
(@VARDMADRA, 4, 0, 'Return to Jotunheim and tell them to keep him asleep until I arrive. I will judge this vrykul with my own eyes.', 12, 0, 100, 1, 0, 0, 'Vardmadra');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=57889;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(57889,57891,0,'On spellcast Using the Eye of the Lich King cast Through the Eye: Summon Image of Vardmadra'),
(57889,57885,0,'On spellcast Using the Eye of the Lich King cast Through the Eye: Summon Image of a Shadow Cultist');

DELETE FROM `spell_scripts` WHERE `id`=57884;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(57884,1,0,14,57889,0,0,0,0,0,0);

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@LK_EYE;
DELETE FROM `smart_scripts` WHERE `source_type`=1 AND `entryorguid`=@LK_EYE;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@LK_EYE, 1, 0, 1, 62, 0, 100, 0, 10005, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eye of the Lich King - On gossip select - Close gossip'),
(@LK_EYE, 1, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 85, @GOSSIP_CAST, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Eye of the Lich King - On gossip select - Invoker Spellcast Through the Eye: Eye of the Lich King Gossip Force Cast'),
(@LK_EYE, 1, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, @ELM_BUNNY, 10, 0, 0, 0, 0, 0, 'Eye of the Lich King - On gossip select - Set data 0 1 Elm General Purpose Bunny');

UPDATE `creature_template` SET `AIName`='SmartAI',`minlevel`=80,`maxlevel`=80,`exp`=2,`faction_A`=1610,`faction_H`=1610,`unit_flags`=33544, `HoverHeight`=6 WHERE `entry`=@VARDMADRA;
UPDATE `creature_template` SET `AIName`='SmartAI',`minlevel`=80,`maxlevel`=80,`exp`=2,`faction_A`=1610,`faction_H`=1610,`unit_flags`=33544 WHERE `entry`=@SHADOW_CULTIST;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (-121192,@VARDMADRA,@SHADOW_CULTIST);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@SHADOW_CULTIST*100;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-121192, 0, 0, 0, 38, 0, 100, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 21, 20, 0, 0, 0, 0, 0, 0, 'Elm General Purpose Bunny - On data set 0 1 - Say line'),
(@SHADOW_CULTIST, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 8, 0, 0, 0, 6828.99, 3814.678, 621.0696, 0, 'Shadow Cultist - Just summoned - Move to position'),
(@SHADOW_CULTIST, 0, 1, 2, 34, 0, 100, 0, 0, 1, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, @VARDMADRA, 10, 0, 0, 0, 0, 0, 'Shadow Cultist - On movement inform - Turn to Image of Vardmadra'),
(@SHADOW_CULTIST, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, @SHADOW_CULTIST*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist - On movement inform - Run script'),
(@VARDMADRA, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, @SHADOW_CULTIST, 30, 0, 0, 0, 0, 0, 'Image of Vardmadra - Just summoned - Turn to Shadow Cultist'),
(@VARDMADRA, 0, 1, 0, 38, 0, 100, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Vardmadra - On data set 0 1 - Say line'),
(@VARDMADRA, 0, 2, 0, 38, 0, 100, 0, 0, 2, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Vardmadra - On data set 0 2 - Say line'),
(@VARDMADRA, 0, 3, 0, 38, 0, 100, 0, 0, 3, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Vardmadra - On data set 0 3 - Say line'),
(@VARDMADRA, 0, 4, 0, 38, 0, 100, 0, 0, 4, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Vardmadra - On data set 0 4 - Say line'),
(@VARDMADRA, 0, 5, 0, 38, 0, 100, 0, 0, 5, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Vardmadra - On data set 0 5 - Say line'),
(@VARDMADRA, 0, 6, 7, 38, 0, 100, 0, 0, 6, 0, 0, 11, 57884, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Image of Vardmadra - On data set 0 6 - Spellcast Through the Eye: Kill Credit to Master'),
(@VARDMADRA, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Image of Vardmadra - On data set 0 6 - Despawn after 1 second'),

(@SHADOW_CULTIST*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist script - Set unit_field_bytes1 (kneel)'),
(@SHADOW_CULTIST*100, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist script - Say line'),
(@SHADOW_CULTIST*100, 9, 2, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, @VARDMADRA, 10, 0, 0, 0, 0, 0, 'Shadow Cultist script - Set data 0 1 Image of Vardmadra'),
(@SHADOW_CULTIST*100, 9, 3, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist script - Say line'),
(@SHADOW_CULTIST*100, 9, 4, 0, 0, 0, 100, 0, 6500, 6500, 0, 0, 45, 0, 2, 0, 0, 0, 0, 19, @VARDMADRA, 10, 0, 0, 0, 0, 0, 'Shadow Cultist script - Set data 0 2 Image of Vardmadra'),
(@SHADOW_CULTIST*100, 9, 5, 0, 0, 0, 100, 0, 500, 500, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist script - Say line'),
(@SHADOW_CULTIST*100, 9, 6, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist script - Say line'),
(@SHADOW_CULTIST*100, 9, 7, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 45, 0, 3, 0, 0, 0, 0, 19, @VARDMADRA, 10, 0, 0, 0, 0, 0, 'Shadow Cultist script - Set data 0 3 Image of Vardmadra'),
(@SHADOW_CULTIST*100, 9, 8, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist script - Say line'),
(@SHADOW_CULTIST*100, 9, 9, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 45, 0, 4, 0, 0, 0, 0, 19, @VARDMADRA, 10, 0, 0, 0, 0, 0, 'Shadow Cultist script - Set data 0 4 Image of Vardmadra'),
(@SHADOW_CULTIST*100, 9,10, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 45, 0, 5, 0, 0, 0, 0, 19, @VARDMADRA, 10, 0, 0, 0, 0, 0, 'Shadow Cultist script - Set data 0 5 Image of Vardmadra'),
(@SHADOW_CULTIST*100, 9,11, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist script - Remove unit_field_bytes1 (kneel)'),
(@SHADOW_CULTIST*100, 9,12, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist script - Say line'),
(@SHADOW_CULTIST*100, 9,13, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 6816.328, 3801.11, 621.153, 0, 'Shadow Cultist script - Move to position'),
(@SHADOW_CULTIST*100, 9,14, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 45, 0, 6, 0, 0, 0, 0, 19, @VARDMADRA, 30, 0, 0, 0, 0, 0, 'Shadow Cultist script - Set data 0 6 Image of Vardmadra'),
(@SHADOW_CULTIST*100, 9,15, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow Cultist script - Despawn');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (@SUMMON_VARDMADRA,@SUMMON_CULTIST);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10005;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@SUMMON_VARDMADRA,0,0,30,0,@LK_EYE,10,0,1,0,0,'','Spell Through the Eye: Summon Image of Vardmadra will be casted only if target is not within 10y of Eye of the Lichking'),
(13,1,@SUMMON_VARDMADRA,0,0,31,0,3,@ELM_BUNNY,0,0,0,0,'','Spell Through the Eye: Summon Image of Vardmadra targets Elm General Purpose Bunny'),
(13,1,@SUMMON_CULTIST,0,0,31,0,3,@ELM_BUNNY,0,0,0,0,'','Spell Through the Eye: Summon Image of a Shadow Cultist targets Elm General Purpose Bunny'),
(15,10005,0,0,0,9,0,13121,0,0,0,0,0,'','Show gossip option only if player has taken quest Through the Eye'),
(15,10005,0,0,0,1,0,@LK_EYE_CAST,0,0,1,0,0,'','Hide gossip option when aura Using the Eye of the Lich King is present');
