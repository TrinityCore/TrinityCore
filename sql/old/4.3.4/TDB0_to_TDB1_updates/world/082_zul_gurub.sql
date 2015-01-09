DELETE FROM `creature_text` WHERE `entry` IN (52322,52077,52150,52053,52054,52156,52956,52381,52438,52380,52148,52059,52650,52222,52962,52151,52271,52958,52155);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- Witch Doctor Qu'in
(52322, 0, 0, 'Sacrifice yo'' bodies ta Hethiss mah bruddahs, da voodoo will protect you!', 14, 0, 100, 0, 0, 0, 'Witch Doctor Qu''in'),
-- Gurubashi Berserker
(52077, 0, 0, '%s is chasing you. Run!', 42, 0, 100, 0, 0, 0, 'Gurubashi Berserker - Casting Pursuit emote'),
(52077, 1, 0, '%s is chasing $n.', 16, 0, 100, 0, 0, 0, 'Gurubashi Berserker - Casting Pursuit'),
-- Jin''do the Godbreaker
(52150, 0, 0, 'No... NOOOO!!!', 14, 0, 100, 0, 0, 24255, 'Jin''do the Godbreaker - Defeated'),
-- Zanzil
(52053, 0, 0, 'What? You''ve come to laugh at Zanzil, too? Not again! I''ll make you pay!', 14, 0, 100, 0, 0, 24337, 'Zanzil - Aggro'),
(52053, 1, 0, '%s begins to resurrect a swarm of |cFFCC0000Zanzili Zombies|r!', 41, 0, 100, 0, 0, 24352, 'Zanzil to Zanzil - Zanzili Zombies emote'),
(52053, 2, 0, 'Rise up! Zanzil''s elixir gives you life!', 14, 0, 100, 0, 0, 24352, 'Zanzil to Zanzil - Casting Zanzil''s Resurrection Elixir'),
(52053, 3, 0, '%s fills the area with a |cFF33FF00toxic gas|r!', 41, 0, 100, 0, 0, 24341, 'Zanzil to Zanzil - Zanzil''s Graveyard Gas emote'),
(52053, 4, 0, 'Breathe deep, friends! Breathe it all in!', 14, 0, 100, 0, 0, 24341, 'Zanzil to Zanzil - Casting Zanzil''s Graveyard Gas'),
(52053, 5, 0, '%s begins to resurrect a |cFF3366CCZanzili Berserker|r!', 41, 0, 100, 0, 0, 24350, 'Zanzil to Zanzil - Casting Zanzili Berserker emote'),
(52053, 6, 0, 'Go, little one! Fight them! KILL THEM!', 14, 0, 100, 0, 0, 24350, 'Zanzil to Zanzil - Casting Zanzil''s Resurrection Elixir (Brute)'),
(52053, 7, 0, 'How does that taste?', 14, 0, 100, 0, 0, 24343, 'Zanzil - Killing a Player'),
(52053, 8, 0, 'You''ll all suffer for this! Zul''Gurub is NOTHING without Zan... Zan...', 14, 0, 100, 0, 0, 24338, 'Zanzil - Death'),
-- Zanzili Berserker
(52054, 0, 0, '%s is chasing $n.', 16, 0, 100, 0, 0, 0, 'Zanzili Berserker - Casting Pursuit'),
(52054, 1, 0, '%s is chasing you. Run!', 42, 0, 100, 0, 0, 0, 'Zanzili Berserker - Casting Pursuit emote'),
-- Chained Spirit
(52156, 0, 0, 'I am released through you! Avenge me!', 15, 0, 100, 0, 0, 0, 'Chained Spirit'),
-- Zandalari Juggernaut
(52956, 0, 0, 'Ancestors be beside me, let ''dem hear yo'' voice!', 14, 14, 100, 0, 0, 0, 'Zandalari Juggernaut'),
-- Venomancer T'Kulu
(52381, 0, 0, 'T''kulu''s death removes the protections from a nearby cauldron!', 41, 0, 100, 0, 0, 0, 'Venomancer T''Kulu'),
-- Mortaxx
(52438, 0, 0, 'CLIMB.', 12, 0, 100, 0, 0, 0, 'Mortaxx'),
-- Venomancer Maur
(52380, 0, 0, 'Mauri''s death removes the protections from a nearby cauldron!', 41, 0, 100, 0, 0, 0, 'Venomancer Mauri'),
-- Jin'do the Godbreaker
(52148, 0, 0, 'Meddlesome insects! Now you will feel my wrath!', 14, 0, 100, 0, 0, 24268, 'Jin''do the Godbreaker - Intro'),
(52148, 1, 0, 'Welcome to de great show, friends. Just wait ''til ya see what I got in store for ya.', 14, 0, 100, 0, 0, 24254, 'Jin''do the Godbreaker - Aggro'),
(52148, 2, 0, 'Jin''do charges his weapon with the Shadows of Hakkar!', 41, 0, 100, 0, 0, 0, 'Jin''do the Godbreaker - Casting Shadows of Hakkar'),
(52148, 3, 0, 'Now, have a taste of Jin''do''s true powah!', 14, 0, 100, 0, 0, 24267, 'Jin''do the Godbreaker - Begin Spirit Phase'),
-- High Priestess Kilnara
(52059, 0, 0, 'No. NO! Get out! Leave me here with the memory of my sister!', 14, 0, 100, 0, 0, 24269, 'High Priestess Kilnara - Aggro'),
(52059, 1, 0, 'Feel me agony!', 14, 0, 100, 0, 0, 24284, 'High Priestess Kilnara to Wave of Agony - Casting Wave of Agony'),
(52059, 2, 0, 'What have you done? I can''t... control... RRAAAARRRGHHH!', 14, 0, 100, 0, 0, 24286, 'High Priestess Kilnara - Transform 1'),
(52059, 3, 0, 'Haaa ha ha haa!  Now, heathens... face the TRUE might of Bethekk!', 14, 0, 100, 0, 0, 24287, 'High Priestess Kilnara - Transform 2'),
(52059, 4, 0, 'I told you to leave!', 14, 0, 100, 0, 0, 24277, 'High Priestess Kilnara - Killing a Player'),
(52059, 5, 0, 'This body is useless!', 14, 0, 100, 0, 0, 24274, 'High Priestess Kilnara - Death'),
-- Shadow of Hakkar
(52650, 0, 0, 'Be freed, insects. I will deal with you another time.', 14, 0, 100, 0, 0, 24243, 'Shadow of Hakkar to Jin''do the Godbreaker'),
-- Spirit of Hakkar
(52222, 0, 0, 'Your deceit is unforgivable, Jin''do. You spit in the face of a god!', 14, 0, 100, 0, 0, 24246, 'Spirit of Hakkar to Jin''do the Godbreaker'),
(52222, 1, 0, 'You overstepped your bounds, Jin''do. You toy with powers that are beyond you. Have you forgotten who I am? Have you forgotten what I can do?!', 14, 0, 100, 0, 0, 24244, 'Spirit of Hakkar to Jin''do the Godbreaker'),
-- Zandalari Archon
(52962, 0, 0, 'Ancients of Zandalar, mark ''dem for de black road.', 14, 14, 100, 0, 0, 0, 'Zandalari Archon'),
-- Bloodlord Mandoki
(52151, 0, 0, 'Make peace, worms.  I be deliverin'' you to Hakkar myself!', 14, 0, 100, 0, 0, 24289, 'Bloodlord Mandokir - Aggro'),
(52151, 1, 0, 'Ha ha ha! Is that all you got?', 14, 0, 100, 0, 0, 24293, 'Bloodlord Mandokir - Killing A Player - Killing A Player'),
(52151, 1, 1, 'Fall to my feet.  Fall to Mandokir, the bloodlord!', 14, 0, 100, 0, 0, 24295, 'Bloodlord Mandokir - Ressurecting Ohgan - Killing A Player'),
(52151, 1, 2, 'Your broken body belongs to Hakkar.', 14, 0, 100, 0, 0, 24294, 'Bloodlord Mandokir - Killing A Player'),
(52151, 2, 0, 'Go an'' get dem, Ohgan! We WON''T be fooled again!', 14, 0, 100, 0, 0, 24298, 'Bloodlord Mandokir - Dismounting Ohgan'),
(52151, 3, 0, '|TInterface\Icons\ability_heroicleap.blp:20|t%s begins to cast |cFFFF0000|Hspell:96740|h[Devastating Slam]|h|r!', 41, 0, 100, 0, 0, 0, 'Bloodlord Mandokir to Devastating Slam - Casting Devastating Slam emote'),
(52151, 4, 0, 'Rise, Ohgan! Rise, and fight for your master!', 14, 0, 100, 0, 0, 24299, 'Bloodlord Mandokir'),
(52151, 5, 0, '%s goes into a frenzy!', 16, 0, 100, 0, 0, 24291, 'Bloodlord Mandokir - Decapitate - Emote'),
(52151, 6, 0, 'Off with your head!', 14, 0, 100, 0, 0, 24291, 'Bloodlord Mandokir - Decapitate'),
(52151, 7, 0, 'My blood feeds Hakkar! My soul... feeds... Jin''do!', 14, 0, 100, 0, 0, 24290, 'Bloodlord Mandokir - Death'),
-- Hazza'rah
(52271, 0, 0, 'Today, you''ll wish you never stirred from your bed!', 14, 0, 100, 0, 0, 24247, 'Hazza''rah - Aggro'),
(52271, 1, 0, 'Let us see what horrors stir within your nightmares!', 14, 0, 100, 0, 0, 24249, 'Hazza''rah to Hazza''rah - Nightmare'),
(52271, 1, 1, 'Slumber... another dream awaits you...', 14, 0, 100, 0, 0, 24251, 'Hazza''rah to Hazza''rah - Nightmare'),
(52271, 3, 0, 'My spirit dreams no longer...', 14, 0, 100, 0, 0, 24248, 'Hazza''rah - Death'),
-- Zandalari Hierophant
(52958, 0, 0, 'Dis land was taken from us in a tide of blood.', 12, 14, 100, 1, 0, 0, 'Zandalari Hierophant'),
(52958, 1, 0, 'Ancients of Zandalar, grant dis one da power ta'' mock death itself!', 14, 14, 100, 0, 0, 0, 'Zandalari Hierophant'),
-- High Priest Venoxis
(52155, 0, 0, 'You disssssturb the plans of Gurubashi, little one.  It''sss too late for you.  Too late for all of you!', 14, 0, 100, 0, 0, 24326, 'High Priest Venoxis - Aggro'),
(52155, 1, 0, 'Yesss...ssssuccumb to the venom...', 14, 0, 100, 0, 0, 24320, 'High Priest Venoxis - Casting Bloodvenom - Casting Bloodvenom'),
(52155, 2, 0, 'Let the coils of death unfurl!', 14, 0, 100, 0, 0, 24319, 'High Priest Venoxis - Transform'),
(52155, 3, 0, 'Hisss word, FILLS me, MY BLOOD IS VENOM, AND YOU WILL BATHE IN THE GLORY OF THE SNAKE GOD!!!', 14, 0, 100, 0, 0, 24321, 'High Priest Venoxis - Casting Word of Hethiss'),
(52155, 4, 0, '|TInterface\Icons\ability_creature_poison_06.blp:20|t High Priest Venoxis begins casting |cFFFF0000|Hspell:96637|h[Bloodvenom]|h|r!', 41, 0, 100, 0, 0, 0, 'High Priest Venoxis - Casting Bloodvenom emote'),
(52155, 5, 0, 'High Priest Venoxis is exhausted!', 41, 0, 100, 0, 0, 0, 'High Priest Venoxis - '),
(52155, 6, 0, 'The mortal coil unwindsss...', 14, 0, 100, 0, 0, 24322, 'High Priest Venoxis to Army of the Dead Ghoul - Killing a Player'),
(52155, 7, 0, 'My death means...nothing...', 14, 0, 100, 0, 0, 24318, 'High Priest Venoxis - Death');
