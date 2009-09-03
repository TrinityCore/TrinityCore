UPDATE `creature_template` SET `ScriptName`='npc_crusade_persuaded' WHERE `entry` IN (28939,28940,28610);

update item_template set spellppmRate_1 = 1 where entry = 39371; -- persuader


DELETE FROM script_texts WHERE entry BETWEEN -1609600 AND -1609501;
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
-- How To Win Friends And Influence Enemies
   (-1609501, 'I\'ll tear the secrets from your soul! Tell me about the "Crimson Dawn" and your life may be spared!',0,0,0,0,'player SAY_PERSUADE1'),
   (-1609502, 'Tell me what you know about "Crimson Dawn" or the beatings will continue!',0,0,0,0,'player SAY_PERSUADE2'),
   (-1609503, 'I\'m through being courteous with your kind, human! What is the "Crimson Dawn?"',0,0,0,0,'player SAY_PERSUADE3'),
   (-1609504, 'Is your life worth so little? Just tell me what I need to know about "Crimson Dawn" and I\'ll end your suffering quickly.',0,0,0,0,'player SAY_PERSUADE4'),
   (-1609505, 'I can keep this up for a very long time, Scarlet dog! Tell me about the "Crimson Dawn!"',0,0,0,0,'player SAY_PERSUADE5'),
   (-1609506, 'What is the "Crimson Dawn?"',0,0,0,0,'player SAY_PERSUADE6'),
   (-1609507, '"Crimson Dawn!" What is it! Speak!',0,0,0,0,'player SAY_PERSUADE7'),
   (-1609508, 'You\'ll be hanging in the gallows shortly, Scourge fiend!',0,0,0,0,'crusader SAY_CRUSADER1'),
   (-1609509, 'You\'ll have to kill me, monster! I will tell you NOTHING!',0,0,0,0,'crusader SAY_CRUSADER2'),
   (-1609510, 'You hit like a girl. Honestly. Is that the best you can do?',0,0,0,0,'crusader SAY_CRUSADER3'),
   (-1609511, 'ARGH! You burned my last good tabard!',0,0,0,0,'crusader SAY_CRUSADER4'),
   (-1609512, 'Argh... The pain... The pain is almost as unbearable as the lashings I received in grammar school when I was but a child.',0,0,0,0,'crusader SAY_CRUSADER5'),
   (-1609513, 'I used to work for Grand Inquisitor Isillien! Your idea of pain is a normal mid-afternoon for me!',0,0,0,0,'crusader SAY_CRUSADER6'),
   (-1609514, 'I\'ll tell you everything! STOP! PLEASE!',0,0,0,20,'break crusader SAY_PERSUADED1'),
   (-1609515, 'We... We have only been told that the "Crimson Dawn" is an awakening. You see, the Light speaks to the High General. It is the Light...',0,0,0,20,'break crusader SAY_PERSUADED2'),
   (-1609516, 'The Light that guides us. The movement was set in motion before you came... We... We do as we are told. It is what must be done.',0,0,0,20,'break crusader SAY_PERSUADED3'),
   (-1609517, 'I know very little else... The High General chooses who may go and who must stay behind. There\'s nothing else... You must believe me!',0,0,0,20,'break crusader SAY_PERSUADED4'),
   (-1609518, 'LIES! The pain you are about to endure will be talked about for years to come!',0,0,0,0,'break crusader SAY_PERSUADED5'),
   (-1609519, 'NO! PLEASE! There is one more thing that I forgot to mention... A courier comes soon... From Hearthglen. It...',0,0,0,20,'break crusader SAY_PERSUADED6'),
-- Ambush At The Overlook
   (-1609531, 'Hrm, what a strange tree. I must investigate.',0,0,0,0,'Scarlet Courier SAY_TREE1'),
   (-1609532, 'What''s this!? This isn''t a tree at all! Guards! Guards!',0,0,0,0,'Scarlet Courier SAY_TREE2'),
-- Bloody Breakout
   (-1609561, 'I\'ll need to get my runeblade and armor... Just need a little more time.',0,0,0,399,'Koltira Deathweaver SAY_BREAKOUT1'),
   (-1609562, 'I\'m still weak, but I think I can get an anti-magic barrier up. Stay inside it or you\'ll be destroyed by their spells.',0,0,0,0,'Koltira Deathweaver SAY_BREAKOUT2'),
   (-1609563, 'Maintaining this barrier will require all of my concentration. Kill them all!',0,0,0,16,'Koltira Deathweaver SAY_BREAKOUT3'),
   (-1609564, 'There are more coming. Defend yourself! Don\'t fall out of the anti-magic field! They\'ll tear you apart without its protection!',0,0,0,0,'Koltira Deathweaver SAY_BREAKOUT4'),
   (-1609565, 'I can\'t keep barrier up much longer... Where is that coward?',0,0,0,0,'Koltira Deathweaver SAY_BREAKOUT5'),
   (-1609566, 'The High Inquisitor comes! Be ready, death knight! Do not let him draw you out of the protective bounds of my anti-magic field! Kill him and take his head!',0,0,0,0,'Koltira Deathweaver SAY_BREAKOUT6'),
   (-1609567, 'Stay in the anti-magic field! Make them come to you!',0,0,0,0,'Koltira Deathweaver SAY_BREAKOUT7'),
   (-1609568, 'The death of the High Inquisitor of New Avalon will not go unnoticed. You need to get out of here at once! Go, before more of them show up. I\'ll be fine on my own.',0,0,0,0,'Koltira Deathweaver SAY_BREAKOUT8'),
   (-1609569, 'I\'ll draw their fire, you make your escape behind me.',0,0,0,0,'Koltira Deathweaver SAY_BREAKOUT9'),
   (-1609570, 'Your High Inquisitor is nothing more than a pile of meat, Crusaders! There are none beyond the grasp of the Scourge!',0,1,0,0,'Koltira Deathweaver SAY_BREAKOUT10'),
   (-1609581, 'The Crusade will purge your kind from this world!',0,1,0,0,'High Inquisitor Valroth start'),
   (-1609582, 'It seems that I\'ll need to deal with you myself. The High Inquisitor comes for you, Scourge!',0,1,0,0,'High Inquisitor Valroth aggro'),
   (-1609583, 'You have come seeking deliverance? I have come to deliver!',0,0,0,0,'High Inquisitor Valroth yell'),
   (-1609584, 'LIGHT PURGE YOU!',0,0,0,0,'High Inquisitor Valroth yell'),
   (-1609585, 'Coward!',0,0,0,0,'High Inquisitor Valroth yell'),
   (-1609586, 'High Inquisitor Valroth\'s remains fall to the ground.',0,2,0,0,'High Inquisitor Valroth death');
