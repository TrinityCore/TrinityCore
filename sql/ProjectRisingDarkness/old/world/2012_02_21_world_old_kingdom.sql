/* Ahn'kahet: The Old Kingdom */

-- Elder Nadox
DELETE FROM `script_texts` WHERE  `npc_entry`=29309;
DELETE FROM `creature_text` WHERE  `entry`=29309;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
('29309', '0', '0', 'The secrets of the deep shall remain hidden.', '14', '0', '0.0', '0', '0', '14033', 'Nadox SAY_AGGRO'),
('29309', '1', '0', 'Sleep now, in the cold dark.', '14', '0', '0.0', '0', '0', '14036', 'Nadox SAY_SLAY'),
('29309', '1', '1', 'Perhaps we will be allies soon.', '14', '0', '0.0', '0', '0', '14038', 'Nadox SAY_SLAY'),
('29309', '1', '2', 'For the Lich King!', '14', '0', '0.0', '0', '0', '14037', 'Nadox SAY_SLAY'),
('29309', '2', '0', 'Master, is my service complete?', '14', '0', '0.0', '0', '0', '14039', 'Nadox SAY_DEATH'),
('29309', '3', '0', 'Shhhad ak kereeesshh chak-k-k!', '14', '0', '0.0', '0', '0', '14035', 'Nadox SAY_EGG_SAC'),
('29309', '3', '1', 'The young must not grow hungry...', '14', '0', '0.0', '0', '0', '14034', 'Nadox SAY_EGG_SAC'),
('29309', '4', '0', 'An Ahn\'kahar Guardian hatches!', '41', '0', '0.0', '0', '0', '0', 'Nadox EMOTE_SUMMON');

-- Herald Volazj
DELETE FROM `script_texts` WHERE  `npc_entry`=29311;
DELETE FROM `creature_text` WHERE  `entry`=29311;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(29311, 0, 0, 'Shgla\'yos plahf mh\'naus.', 14, 0, 0, 0, 0, 14043, 'Herald SAY_AGGRO'),
(29311, 1, 0, 'They who dine on lost souls know only hunger.', 15, 0, 0, 0, 0, 0, 'Herald WHISPER_AGGRO'),
(29311, 2, 0, 'Gul\'kafh an\'shel. Yoq\'al shn ky ywaq nuul.', 14, 0, 0, 0, 0, 14044, 'Herald SAY_INSANITY'),
(29311, 3, 0, 'Gaze into the void. It is the perpetuity in which they dwell.', 15, 0, 0, 0, 0, 0, 'Herald WHISPER_INSANITY'),
(29311, 4, 0, 'Ywaq puul skshgn: on\'ma yeh\'glu zuq.', 14, 0, 0, 0, 0, 14045, 'Herald SAY_SLAY1'),
(29311, 5, 0, 'They drink your fear: it is the blood of life.', 15, 0, 0, 0, 0, 0, 'Herald WHISPER_SLAY1'),
(29311, 6, 0, 'Ywaq ma phgwa\'cul hnakf.', 14, 0, 0, 0, 0, 14046, 'Herald SAY_SLAY2'),
(29311, 7, 0, 'They are the whisper on the shivering wind.', 15, 0, 0, 0, 0, 0, 'Herald WHISPER_SLAY2'),
(29311, 8, 0, 'Ywaq maq oou; ywaq maq ssaggh. Ywaq ma shg\'fhn.', 14, 0, 0, 0, 14047, 14049, 'Herald SAY_SLAY3'),
(29311, 9, 0, 'They do not die; they do not live. They are outside the cycle.', 15, 0, 0, 0, 0, 0, 'Herald WHISPER_SLAY3'),
(29311, 10, 0, 'Iilth vwah, uhn\'agth fhssh za.', 14, 0, 0, 0, 0, 14048, 'Herald SAY_DEATH'),
(29311, 11, 0, 'Where one falls, many shall take its place.', 15, 0, 0, 0, 0, 0, 'Herald WHISPER_DEATH');

-- Jedoga Shadowseeker
DELETE FROM `script_texts` WHERE  `npc_entry`=29310;
DELETE FROM `creature_text` WHERE  `entry`=29310;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(29310, 0, 0, 'The elements themselves will rise up against the civilized world! Only the faithful will be spared!', 14, 0, 0, 0, 0, 14352, 'Shadowseeker SAY_INTRO'),
(29310, 0, 1, 'Immortality can be yours. But only if you pledge yourself fully to Yogg-Saron!', 14, 0, 0, 0, 0, 14353, 'Shadowseeker SAY_INTRO'),
(29310, 0, 2, 'Here on the very borders of his domain. You will experience powers you would never have imagined!', 14, 0, 0, 0, 0, 14354, 'Shadowseeker SAY_INTRO'),
(29310, 0, 3, 'You have traveled long and risked much to be here. Your devotion shall be rewarded.', 14, 0, 0, 0, 0, 14355, 'Shadowseeker SAY_INTRO'),
(29310, 0, 4, 'The faithful shall be exalted! But there is more work to be done. We will press on until all of Azeroth lies beneath his shadow!', 14, 0, 0, 0, 0, 14356, 

'Shadowseeker SAY_INTRO'),
(29310, 1, 0, 'These are sacred halls! Your intrusion will be met with death.', 14, 0, 0, 0, 0, 14343, 'Shadowseeker SAY_AGGRO'),
(29310, 2, 0, 'Who among you is devoted?', 14, 0, 0, 0, 0, 14344, 'Shadowseeker SAY_SACRIFICE'),
(29310, 2, 1, 'You there! Step forward!', 14, 0, 0, 0, 0, 14345, 'Shadowseeker SAY_SACRIFICE'),
(29310, 3, 0, 'Yogg-Saron, grant me your power!', 14, 0, 0, 0, 0, 14346, 'Shadowseeker SAY_HERALD'),
(29310, 3, 1, 'Master, a gift for you!', 14, 0, 0, 0, 0, 14347, 'Shadowseeker SAY_HERALD'),
(29310, 4, 0, 'Glory to Yogg-Saron!', 14, 0, 0, 0, 0, 14348, 'Shadowseeker SAY_SLAY'),
(29310, 4, 1, 'You are unworthy!', 14, 0, 0, 0, 0, 14349, 'Shadowseeker SAY_SLAY'),
(29310, 4, 2, 'Get up! You haven\'t suffered enough.', 14, 0, 0, 0, 0, 14350, 'Shadowseeker SAY_SLAY'),
(29310, 5, 0, 'Do not expect your sacrilege... to go unpunished.', 14, 0, 0, 0, 0, 14351, 'Shadowseeker SAY_DEATH');

-- Prince Taldaram
DELETE FROM `script_texts` WHERE  `npc_entry`=29308;
DELETE FROM `creature_text` WHERE  `entry`=29308;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(29308, 0, 0, 'I will feast on your remains.', 14, 0, 0, 0, 0, 14360, 'Prince taldaram SAY_AGGRO'),
(29308, 1, 0, 'Your heartbeat is music to my ears.', 14, 0, 0, 0, 0, 14361, 'Prince taldaram SAY_FEED'),
(29308, 1, 1, 'I am nowhere. I am everywhere. I am the watcher, unseen.', 14, 0, 0, 0, 0, 14362, 'Prince taldaram SAY_FEED'),
(29308, 2, 0, 'So appetizing.', 14, 0, 0, 0, 0, 14363, 'Prince taldaram SAY_VANISH'),
(29308, 2, 1, 'Fresh, warm blood. It has been too long.', 14, 0, 0, 0, 0, 14364, 'prince taldaram SAY_VANISH'),
(29308, 3, 0, 'I will drink no blood before it\'s time.', 14, 0, 0, 0, 0, 14366, 'Prince taldaram SAY_SLAY'),
(29308, 3, 1, 'One final embrace.', 14, 0, 0, 0, 0, 14367, 'Prince taldaram SAY_SLAY'),
(29308, 4, 0, 'Still I hunger, still I thirst.', 14, 0, 0, 0, 0, 14368, 'Prince taldaram SAY_DEATH');

/* Ahn'kahet: The Old Kingdom */
