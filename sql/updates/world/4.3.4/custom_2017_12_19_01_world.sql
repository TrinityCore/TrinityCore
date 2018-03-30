
-- Template Updates
UPDATE `creature_template` SET `scriptname`= 'boss_baron_ashbury', `flags_extra`= 1 WHERE `entry`= 46962;
UPDATE `creature_template` SET `AIName`= '', `flags_extra`= 1, `scriptname`= 'boss_lord_godfrey' WHERE `entry`= 46964;
UPDATE `creature_template` SET `AIName`= '', `scriptname`= 'npc_sfk_bloodthirsty_ghoul' WHERE `entry`= 50561;
UPDATE `creature_template` SET `flags_extra`= 130, `InhabitType`= 4 WHERE `entry`= 52065;
UPDATE `creature_template` SET `scriptname`= 'boss_baron_silverlaine', `flags_extra`= 1 WHERE `entry`= 3887;
UPDATE `creature_template` SET `flags_extra`= 130 WHERE `entry` IN (51047, 51080, 51085, 50934);
UPDATE `creature_template` SET `scriptname`= 'npc_wolf_master_nandos' WHERE `entry`= 50851;
UPDATE `creature_template` SET `scriptname`= 'npc_razorclaw_the_butcher'  WHERE `entry`= 50869;
UPDATE `creature_template` SET `scriptname`= 'npc_odo_the_blindwatcher'  WHERE `entry`= 50857;
UPDATE `creature_template` SET `scriptname`= 'npc_rethilgore'  WHERE `entry`= 50834;
UPDATE `creature_template` SET `scriptname`= 'boss_commander_springvale', `AIName`= '', `flags_extra`= 1  WHERE `entry`= 4278;
UPDATE `creature_template` SET `flags_extra`= 130, `unit_flags`= 33554688 WHERE `entry`= 50547;
UPDATE `creature_template` SET `faction`= 14, `minlevel`= 87, `maxlevel`= 87, `flags_extra`= 130, `unit_flags`= 33554432 WHERE `entry` IN (50503, 51258);
UPDATE `creature_template` SET `AIName`= '', `scriptname`= 'boss_lord_walden', `flags_extra`= 1 WHERE `entry`= 46963;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 14, `flags_extra`= 130, `modelid1`= 1126, `modelid2`= 23767, `InhabitType`= 4, `unit_flags`= unit_flags | 256 | 512 WHERE `entry`= 50522;
UPDATE `creature_template` SET `scriptname`= 'npc_wailing_guardsman' WHERE `entry`= 50613;
UPDATE `creature_template` SET `scriptname`= 'npc_tormented_officer' WHERE `entry`= 50615;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `faction`= 14, `unit_flags`= 33554432, `flags_extra`= 130 WHERE `entry`= 50503;
UPDATE `creature_template` SET `flags_extra`= 130 WHERE `entry` IN (50611, 50604, 51085, 51080, 50934, 51047);
UPDATE `creature_template` SET `unit_flags`= 768, `unit_flags2`= 33556480 WHERE `entry`= 47031;

-- Creature Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (46964, 46962, 3887, 4278, 46963, 47293, 47006, 47027, 48124, 47862, 47294);
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(46964, 0, 0, 'Ivar''s pack failed horribly, so now he sends mercenaries. No matter, your journey ends in agony.', 14, 0, 100, 0, 0, 0, 'Lord Godfrey - Aggro Alliance'),
(46964, 1, 0, 'That bitch Sylvanas sent you too, did she? No matter, your journey ends in agony.', 14, 0, 100, 0, 0, 0, 'Lord Godfrey - Aggro Horde'),
(46964, 2, 0, 'Murder never gets old.', 14, 0, 100, 0, 0, 0, 'Lord Godfrey - Aggro Horde'),
(46964, 2, 1, 'This is the quality of assassin sent to kill me? Laughable.', 14, 0, 100, 0, 0, 0, 'Lord Godfrey - Aggro Horde'),
(46964, 3, 0, '|TInterface\\Icons\\INV_FIREARM_2H_RIFLE_CATACLYSM_B_01.BLP:20|t%s begins to cast |cFFFF0000|Hspell:93520|h[Pistol Barrage]|h|r!', 41, 0, 100, 0, 0, 0, 'Lord Godfrey Pistol Barrage'),
(46964, 4, 0, 'I thank you for the clean death. I would not have done the same...', 14, 0, 100, 0, 0, 0, 'Lord Godfrey'),
(46962, 1, 0, 'Tally ho! The hunt begins!', 14, 0, 100, 0, 0, 0, 'Baron Ashbury'),
(46962, 2, 0, 'This is just too easy...', 14, 0, 100, 0, 0, 0, 'Baron Ashbury'),
(46962, 3, 0, '|TInterface\\Icons\\spell_holy_healingaura.blp:20|tBaron Ashbury begins to channel |cFFFF0000|Hspell:93468|h''Stay of Execution''|h|r !', 41, 0, 100, 0, 0, 0, 'Baron Ashbury'),
(46962, 4, 0, 'HA! Let''s at least keep it interesting.', 14, 0, 100, 0, 0, 0, 'Baron Ashbury'),
(46962, 5, 0, 'I grow tired of this hunt... Time to die!', 14, 0, 100, 0, 0, 0, 'Baron Ashbury'),
(46962, 6, 0, 'Killed by lowly commoners, how droll...', 14, 0, 100, 0, 0, 0, 'Baron Ashbury'),
(3887, 0, 0, 'Leave this accursed place at once!', 14, 0, 100, 0, 0, 0, 'Baron Silverlaine - Aggro'),
(3887, 1, 0, 'This death is only a temporary respite from my curse.', 14, 0, 100, 0, 0, 0, 'Baron Silverlaine - Death'),
(3887, 2, 0, 'I hope your spirit finds solace.', 14, 0, 100, 0, 0, 0, 'Baron Silverlaine - Slay 1'),
(3887, 2, 1, 'May you rest in peace.', 14, 0, 100, 0, 0, 0, 'Baron Silverlaine - Slay 2'),
(4278, 0, 0, 'Intruders in the keep! To arms!', 14, 0, 100, 0, 0, 0, 'Commander Springvale - Aggro'),
(4278, 1, 0, 'Repel the intruders!', 14, 0, 100, 0, 0, 0, 'Commander Springvale - Summon Adds'),
(4278, 2, 0, 'The attackers weaken!', 14, 0, 100, 0, 0, 0, 'Commander Springvale - Slay 1'),
(4278, 2, 1, 'One step closer to victory!', 14, 0, 100, 0, 0, 0, 'Commander Springvale - Slay 2'),
(4278, 3, 0, 'Our vigilance is eternal...', 14, 0, 100, 0, 0, 0, 'Commander Springvale - Death'),
(46963, 0, 0, 'Even here I find myself beset by fools!', 14, 0, 100, 0, 0, 0, 'Lord Walden - Aggro'),
(46963, 1, 0, 'This childish effort ends now!', 14, 0, 100, 0, 0, 0, 'Lord Walden - Slay 1'),
(46963, 1, 1, 'You shall annoy me no longer!', 14, 0, 100, 0, 0, 0, 'Lord Walden - Slay 2'),
(46963, 2, 0, 'My new life was just beginning...', 14, 0, 100, 0, 0, 0, 'Lord Walden - Death'),
-- Belmont
(47293, 0, 0, 'You''re more skilled in combat than I thought.', 12, 0, 100, 1, 0, 0, 'Deathstalker Commander Belmont to Player'),
(47293, 1, 0, 'Very well then. Let''s get the courtyard door open so we can continue our mission!', 12, 0, 100, 1, 0, 0, 'Deathstalker Commander Belmont to Player'),
(47293, 2, 0, 'This lock should be easy enough to pick.', 12, 0, 100, 1, 0, 0, 'Deathstalker Commander Belmont to Player'),
(47293, 3, 0, 'There we go!', 12, 0, 100, 0, 0, 0, 'Deathstalker Commander Belmont to Player'),
(47293, 4, 0, 'Excellent. Now, to plague this area and move on to-', 12, 0, 100, 396, 0, 0, 'Deathstalker Commander Belmont to Player'),
(47293, 5, 0, 'Cromush! What''re you doing here? This is a covert operation!', 12, 0, 100, 5, 0, 0, 'Deathstalker Commander Belmont to Player'),
(47293, 6, 0, 'My apologies, Cromush, but I assure you there is no problem. We are using an extremely dilute plague.', 12, 0, 100, 396, 0, 0, 'Deathstalker Commander Belmont to Player'),
(47293, 7, 0, 'In fact, it really only serves to scare off the worgen from trying to follow us in here. It''s completely harmless.', 12, 0, 100, 396, 0, 0, 'Deathstalker Commander Belmont to Player'),
(47293, 8, 0, 'The time has come, soldiers! Godfrey lies just ahead! Have no mercy! We fight-', 12, 0, 100, 396, 0, 0, 'Deathstalker Commander Belmont to Player'),
(47293, 9, 0, 'You''d better hurry up if you want in on all the fun.', 12, 0, 100, 153, 0, 0, 'Deathstalker Commander Belmont to Player'),
(47293, 10, 0, 'Why is the door shut? What in Sylvanas'' name is going on here...', 12, 0, 100, 396, 0, 0, 'Deathstalker Commander Belmont to Player'),
(47293, 11, 0, 'Cromush! What happened?', 12, 0, 100, 396, 0, 0, 'Deathstalker Commander Belmont to Player'),
(47293, 12, 0, 'You''ll pay for this Godfrey!', 12, 0, 100, 397, 0, 0, 'Deathstalker Commander Belmont to Player'),
-- Cromush
(47294, 0, 0, 'Unless I''m mistaken, the Warchief explicity forbids using the full plague, no matter the circumstance.', 12, 0, 100, 396, 0, 0, 'High Warlord Cromush to Player'),
(47294, 1, 0, 'Then I''m sure you won''t mind if I accompany you on your mission.', 12, 0, 100, 396, 0, 0, 'High Warlord Cromush to Player'),
(47294, 2, 0, 'FOR THE HORDE!!!', 14, 0, 100, 71, 0, 0, 'High Warlord Cromush to Player'),
(47294, 3, 0, 'The coward...killed them...poisoned...me...', 12, 0, 100, 0, 0, 0, 'High Warlord Cromush to Player'),
-- Ivar
(47006, 0, 0, 'Pathetic.', 12, 0, 100, 1, 0, 0, 'Packleader Ivar Bloodfang to Player'),
(47006, 1, 0, 'Keep moving forward. My men will dispose of this sorry bag of bones.', 12, 0, 100, 1, 0, 0, 'Packleader Ivar Bloodfang to Player'),
(47006, 2, 0, 'Control yourselves! We''re here for Godfrey''s head above all else. Relish in the spoils of war later!', 12, 0, 100, 5, 0, 0, 'Packleader Ivar Bloodfang to Player'),
(47006, 3, 0, 'We have to push forward if we''re to put an end to him. Follow me, I''ll open the courtyard so that you can spearhead our assault.', 12, 0, 100, 0, 0, 0, 'Packleader Ivar Bloodfang to Player'),
(47006, 4, 0, 'What a pathetic lock! Godfrey is going to have to try harder than this if he wants to defeat us.', 12, 0, 100, 0, 0, 0, 'Packleader Ivar Bloodfang to Player'),
(47006, 5, 0, 'The Bloodfang Berserkers begin to salivate heavily.', 16, 0, 100, 0, 0, 0, 'Packleader Ivar Bloodfang to Player'),
(47006, 6, 0, 'The Bloodfang come for you, worgen hunters!', 14, 0, 100, 15, 0, 0, 'Packleader Ivar Bloodfang to Player'),
(47006, 7, 0, 'I''ve picked up Walden''s foul scent. Fill the air with his blood!', 12, 0, 100, 1, 0, 0, 'Packleader Ivar Bloodfang to Player'),
(47006, 8, 0, 'Your time has finally come, Godfrey!', 14, 0, 100, 53, 0, 0, 'Packleader Ivar Bloodfang to Player'),
(47006, 9, 0, 'Attack, my brothers! Make him feel the fury of the pack!', 14, 0, 100, 25, 0, 0, 'Packleader Ivar Bloodfang to Player'),
(47006, 10, 0, 'You''d best hurry if you want any of the spoils.', 12, 0, 100, 0, 0, 0, 'Packleader Ivar Bloodfang to Player'),
(47006, 11, 0, 'I don''t know why the door is closed, heroes. My pack should have already taken care of Godfrey by now...', 12, 0, 100, 1, 0, 0, 'Packleader Ivar Bloodfang to Player'),
(47006, 12, 0, 'We will stand idle no longer! The time to act is now!', 12, 0, 100, 1, 0, 0, 'Packleader Ivar Bloodfang to Player'),
(47006, 13, 0, 'I''ll make sure nothing interferes. Go now heroes! Kill Godfrey!', 12, 0, 100, 0, 0, 0, 'Packleader Ivar Bloodfang to Player'),
(47006, 14, 0, 'Crowley is a disgrace to our kind for giving in to the Forsaken. My pack will show them the true face of the worgen and the relentless fury that comes with our presence!', 12, 0, 100, 5, 0, 0, 'Packleader Ivar Bloodfang to Player'),
-- Bloodfang Berserker
(47027, 0, 0, 'Bones?', 12, 0, 100, 1, 0, 0, 'Bloodfang Berserker'),
-- Rabid Mastiff
(48124, 0, 0, 'The Rabid Mastiff slobbers all over the floor...', 16, 0, 100, 0, 0, 0, 'Rabid Mastiff'),
(48124, 0, 1, 'The dog stares blankly at the wall...', 16, 0, 100, 0, 0, 0, 'Rabid Mastiff'),
(48124, 0, 2, 'A Rabid Mastiff growls...', 16, 0, 100, 0, 0, 0, 'Rabid Mastiff'),
-- Hentry Maleb
(47862, 0, 0, 'Better to rot in this cell than live as a dishonorable traitor.', 12, 0, 100, 1, 0, 0, 'Magistrate Henry Maleb');

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (46964, 49712, 50604, 47030, 93424, 50503,50851, 50923, 50834, 50857, 50869, 50547, 47006, 47031, 47293, 47294);
INSERT INTO `creature_template_addon` (`entry`, `Auras`) VALUES
(46964, '93597'),
(49712, '93597'),
(50503, '93690 67803'),
(50851 , '93853'),
(50923 , '93853'),
(50857 , '93853'),
(50869 , '93853'),
(50834 , '50834');

-- Spell Script Names
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_sfk_summon_bloodthirsty_ghouls',
'spell_sfk_pistol_barrage',
'spell_sfk_pain_and_suffering',
'spell_sfk_summon_worgen_spirit',
'spell_sfk_forsaken_ability',
'spell_sfk_asphyxiate',
'spell_sfk_unholy_power',
'spell_sfk_unholy_empowerment',
'spell_sfk_toxic_coagulant',
'spell_sfk_pistol_barrage_summon',
'spell_sfk_conjure_poisonous_mixture',
'spell_sfk_cursed_bullets');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(93707, 'spell_sfk_summon_bloodthirsty_ghouls'),
(93520, 'spell_sfk_pistol_barrage'),
(93581, 'spell_sfk_pain_and_suffering'),
(93712, 'spell_sfk_pain_and_suffering'), 
(93857, 'spell_sfk_summon_worgen_spirit'),
(7054, 'spell_sfk_forsaken_ability'),
(93423, 'spell_sfk_asphyxiate'),
(93710, 'spell_sfk_asphyxiate'),
(93686, 'spell_sfk_unholy_power'),
(93735, 'spell_sfk_unholy_power'),
(93844, 'spell_sfk_unholy_empowerment'),
(93617, 'spell_sfk_toxic_coagulant'),
(96344, 'spell_sfk_pistol_barrage_summon'),
(93697, 'spell_sfk_conjure_poisonous_mixture'),
(93704, 'spell_sfk_conjure_poisonous_mixture'),
(93629, 'spell_sfk_cursed_bullets'),
(93761, 'spell_sfk_cursed_bullets');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (93564, 93784, 93766, 93599, 93594);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`,  `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 2, 93564, 0, 0, 31, 0, 3, 50561, 0, 0, 0, '', 'Pistol Barrage - Target Bloodthirsty Ghoul'),
(13, 2, 93784, 0, 0, 31, 0, 3, 50561, 0, 0, 0, '', 'Pistol Barrage HC - Target Bloodthirsty Ghoul'),
(13, 1, 93766, 0, 0, 31, 0, 3, 50604, 0, 0, 0, '', 'Dark Archangel - Wings Aura'),
(13, 1, 93599, 0, 0, 31, 0, 3, 46963, 0, 0, 0, '', 'Toxic Coagulant - Target Lord Walden'),
(13, 1, 93594, 0, 0, 31, 0, 3, 46963, 0, 0, 0, '', 'Toxic Cataclyst - Target Lord Walden');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`= 93757;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
('93757', '93766', '0', 'Baron Ashbury Wings - Apply Aura'),
('93757', '93812', '0', 'Baron Ashbury - Archangel Damage Aura');

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (16081, 16085, 16544, 16086, 16544);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(16081, 11, 0, 0, 'achievement_pardon_denied'),
(16085, 11, 0, 0, 'achievement_to_the_ground'),
(16086, 11, 0, 0, 'achievement_bullet_time');

DELETE FROM `spell_dbc` WHERE `Id`= 93716;
INSERT INTO `spell_dbc` (`Id`, `CastingTimeIndex`, `DurationIndex`, `Comment`) VALUES
(93716, 0, 27, 'Shield of the Perfidious');

DELETE FROM `spelleffect_dbc` WHERE `Id`= 155915;
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectMiscValue`, `EffectMiscValueB`, `EffectRadiusIndex`, `EffectRadiusIndexMax`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `EffectSpellId`, `EffectIndex`, `Comment`) VALUES
(155915, 28, 50547, 64, 7,7, 18, 18, 93716, 0, '');

-- Boss Loot
-- Baron Ashbury
UPDATE `creature_template` SET `difficulty_entry_1`= 49708, `lootid`= 46962 WHERE `entry` = 46962;
DELETE FROM `creature_loot_template` WHERE `entry` IN (46962, 49708);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(46962, 6314, 0, 1, 1, 1, 1),
(46962, 6324, 0, 1, 1, 1, 1),
(46962, 6323, 0, 1, 1, 1, 1);

UPDATE `creature_template` SET `lootid`= 49708 WHERE `entry`= 49708;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(49708, 63433, 0, 1, 1, 1, 1),
(49708, 63437, 0, 1, 1, 1, 1),
(49708, 63435, 0, 1, 1, 1, 1),
(49708, 63436, 0, 1, 1, 1, 1),
(49708, 63434, 0, 1, 1, 1, 1);

-- Baron Silverlaine
UPDATE creature_template SET `difficulty_entry_1`= 49709, `lootid`= 3887 WHERE `entry`= 3887;
DELETE FROM `creature_loot_template` WHERE `entry` IN (3887, 49709);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(3887, 6321, 0, 1, 1, 1, 1),
(3887, 6323, 0, 1, 1, 1, 1),
(3887, 60885, -100, 1, 2, 1, 1),
(3887, 60878, -100, 1, 3, 1, 1);

UPDATE `creature_template` SET `lootid`= 49709 WHERE `entry`= 49709;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(49709, 63440, 0, 1, 1, 1, 1),
(49709, 63439, 0, 1, 1, 1, 1),
(49709, 63444, 0, 1, 1, 1, 1),
(49709, 63438, 0, 1, 1, 1, 1),
(49709, 63441, 0, 1, 1, 1, 1);

-- Commander Springvale
UPDATE creature_template SET `difficulty_entry_1`= 49710, `lootid`= 4278 WHERE `entry`= 4278;
DELETE FROM `creature_loot_template` WHERE `entry` IN (4278, 49710);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(4278, 3191, 0, 1, 1, 1, 1),
(4278, 6320, 0, 1, 1, 1, 1),
(4278, 60879, -100, 1, 2, 1, 1),
(4278, 60880, -100, 1, 3, 1, 1);

UPDATE `creature_template` SET `lootid`= 49710 WHERE `entry`= 49710;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(49710, 63448, 0, 1, 1, 1, 1),
(49710, 63449, 0, 1, 1, 1, 1),
(49710, 63447, 0, 1, 1, 1, 1),
(49710, 63446, 0, 1, 1, 1, 1),
(49710, 63445, 0, 1, 1, 1, 1);

-- Lord Walden
UPDATE creature_template SET `difficulty_entry_1`= 49711, `lootid`= 46962 WHERE `entry`= 46962;
DELETE FROM `creature_loot_template` WHERE `entry` IN (46962, 49711);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(46962, 3230, 0, 1, 1, 1, 1),
(46962, 6642, 0, 1, 1, 1, 1),
(46962, 6341, 0, 1, 1, 1, 1),
(46962, 1292, 0, 1, 1, 1, 1),
(46962, 60876, -100, 1, 2, 1, 1),
(46962, 60881, -100, 1, 3, 1, 1);

UPDATE `creature_template` SET `lootid`= 49711 WHERE `entry`= 49711;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(49711, 63455, 0, 1, 1, 1, 1),
(49711, 63454, 0, 1, 1, 1, 1),
(49711, 63452, 0, 1, 1, 1, 1),
(49711, 63450, 0, 1, 1, 1, 1),
(49711, 63453, 0, 1, 1, 1, 1);

-- Lord Godfrey
UPDATE `creature_template` SET `difficulty_entry_1`= 49712, `lootid`= 46964 WHERE `entry`= 46964;
UPDATE `creature_template` SET `lootid`= 49712 WHERE `entry`= 49712;
DELETE FROM `creature_loot_template` WHERE `Entry` IN (46964, 49712);
DELETE FROM `reference_loot_template` WHERE `Entry` IN (469640, 497120, 497121);

INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `Reference`, `MaxCount`) VALUES
(46964, 469640, 100, 1, 469640, 2),
(49712, 497120, 100, 1, 497120, 2),
(49712, 497121, 100, 1, 497121, 1); -- Chaos Orb

INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(469640, 3748, 0, 1, 1, 1, 1),
(469640, 6220, 0, 1, 1, 1, 1),
(469640, 6641, 0, 1, 1, 1, 1),
(469640, 6318, 0, 1, 1, 1, 1),
(469640, 60877, -100, 1, 2, 1, 1),
(469640, 60882, -100, 1, 3, 1, 1),
(497120, 63465, 0, 1, 1, 1, 1),
(497120, 63463, 0, 1, 1, 1, 1),
(497120, 63459, 0, 1, 1, 1, 1),
(497120, 63462, 0, 1, 1, 1, 1),
(497120, 63458, 0, 1, 1, 1, 1),
(497120, 63457, 0, 1, 1, 1, 1),
(497120, 63464, 0, 1, 1, 1, 1),
(497120, 63460, 0, 1, 1, 1, 1),
(497120, 63456, 0, 1, 1, 1, 1),
(497120, 63461, 0, 1, 1, 1, 1),
(497121, 52078, 100, 1, 1, 1, 1);
