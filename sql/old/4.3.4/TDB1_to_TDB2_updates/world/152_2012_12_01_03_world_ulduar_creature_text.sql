DELETE FROM `script_texts` WHERE `entry` BETWEEN -1603341 AND -1603050;
DELETE FROM `creature_text` WHERE `entry`=33350 AND `groupid`=15;
DELETE FROM `creature_text` WHERE `entry` IN (
33515, -- Auriaya
33113, -- Flame Leviathan
32906, -- Freya
32913, -- Elder Ironbranch
32914, -- Elder Stonebark
32915, -- Elder Brightleaf
32845, -- Hodir
33118, -- Ignis
32930, -- Kologarn
33210, -- Expedition Commander
33287, -- Expedition Engineer
33186, -- Razorscale
33233, -- Razorscale Controller
33271, -- General Vezax
33488, -- Saronite Vapor
33293, -- XT-002 Deconstructor
32865  -- Thorim
);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- Auriaya
(33515,0,0,'Some things are better left alone!',14,0,100,0,0,15473,'Auriaya SAY_AGGRO'),
(33515,1,1,'The secret dies with you!',14,0,100,0,0,15474,'Auriaya SAY_SLAY_1'),
(33515,1,2,'There is no escape!',14,0,100,0,0,15475,'Auriaya SAY_SLAY_2'),
(33515,2,0,'Auriaya screams in agony.',16,0,100,0,0,15476,'Auriaya SAY_DEATH'),
(33515,3,0,'You waste my time!',14,0,100,0,0,15477,'Auriaya SAY_BERSERK'),
(33515,4,0,'%s begins to cast Terrifying Screech.',41,0,100,0,0,0,'Auriaya EMOTE_FEAR'),
(33515,5,0,'%s begins to activate the Feral Defender!',41,0,100,0,0,0,'Auriaya EMOTE_DEFENDER'),
-- Flame Leviathan
(33113, 0,0,'Hostile entities detected. Threat assessment protocol active. Primary target engaged. Time minus 30 seconds to re-evaluation.',14,0,100,0,0,15506,'Flame Leviathan SAY_AGGRO'),
(33113, 1,0,'Threat assessment routine modified. Current target threat level: 0. Acquiring new target.',14,0,100,0,0,15521,'Flame Leviathan SAY_SLAY'),
(33113, 2,0,'Total systems failure. Defense protocols breached. Leviathan unit shutting down.',14,0,100,0,0,15520,'Flame Leviathan SAY_DEATH'),
(33113, 3,0,'Threat re-evaluated. Target assessment complete. Changing course.',14,0,100,0,0,15507,'Flame Leviathan SAY_TARGET_1'),
(33113, 3,1,'Pursuit objective modified. Changing course.',14,0,100,0,0,15508,'Flame Leviathan SAY_TARGET_2'),
(33113, 3,2,'Hostile entity stratagem predicted. Rerouting battle function. Changing course.',14,0,100,0,0,15509,'Flame Leviathan SAY_TARGET_3'),
(33113, 4,0,'Orbital countermeasures enabled.',14,0,100,0,0,15510,'Flame Leviathan SAY_HARDMODE'),
(33113, 5,0,'Alert! Static defense system failure. Orbital countermeasures disabled.',14,0,100,0,0,15511,'Flame Leviathan SAY_TOWER_NONE'),
(33113, 6,0,'Hodir''s Fury online. Acquiring target.',14,0,100,0,0,15512,'Flame Leviathan SAY_TOWER_FROST'),
(33113, 7,0,'Mimiron''s Inferno online. Acquiring target.',14,0,100,0,0,15513,'Flame Leviathan SAY_TOWER_FLAME'),
(33113, 8,0,'Freya''s Ward online. Acquiring target.',14,0,100,0,0,15514,'Flame Leviathan SAY_TOWER_NATURE'),
(33113, 9,0,'Thorim''s Hammer online. Acquiring target.',14,0,100,0,0,15515,'Flame Leviathan SAY_TOWER_STORM'),
(33113,10,0,'Unauthorized entity attempting circuit overload. Activating anti-personnel countermeasures.',14,0,100,0,0,15516,'Flame Leviathan SAY_PLAYER_RIDING'),
(33113,11,0,'System malfunction. Diverting power to support systems.',14,0,100,0,0,15517,'Flame Leviathan SAY_OVERLOAD_1'),
(33113,11,1,'Combat matrix overload. Powering do-o-o-own...',14,0,100,0,0,15518,'Flame Leviathan SAY_OVERLOAD_2'),
(33113,11,2,'System restart required. Deactivating weapon systems.',14,0,100,0,0,15519,'Flame Leviathan SAY_OVERLOAD_3'),
(33113,12,0,'%s pursues $n.',41,0,100,0,0,0,'Flame Leviathan EMOTE_PURSUE'),
(33113,13,0,'%s''s circuits overloaded.',41,0,100,0,0,0,'Flame Leviathan EMOTE_OVERLOAD'),
(33113,14,0,'Automatic repair sequence initiated.',41,0,100,0,0,0,'Flame Leviathan EMOTE_REPAIR'),
-- Freya
(32906, 0,0,'The Conservatory must be protected!',14,0,100,0,0,15526,'Freya SAY_AGGRO'),
(32906, 1,0,'Elders grant me your strength!',14,0,100,0,0,15527,'Freya SAY_AGGRO_WITH_ELDER'),
(32906, 2,0,'Forgive me.',14,0,100,0,0,15529,'Freya SAY_SLAY_1'),
(32906, 2,1,'From your death springs life anew!',14,0,100,0,0,15530,'Freya SAY_SLAY_2'),
(32906, 3,0,'His hold on me dissipates. I can see clearly once more. Thank you, heroes.',14,0,100,0,0,15531,'Freya SAY_DEATH'),
(32906, 4,0,'You have strayed too far, wasted too much time!',14,0,100,0,0,15532,'Freya SAY_BERSERK'),
(32906, 5,0,'Eonar, your servant requires aid!',14,0,100,0,0,15528,'Freya SAY_SUMMON_CONSERVATOR'),
(32906, 6,0,'Children, assist me!',14,0,100,0,0,15533,'Freya SAY_SUMMON_TRIO'),
(32906, 7,0,'The swarm of the elements shall overtake you!',14,0,100,0,0,15534,'Freya SAY_SUMMON_LASHERS'),
(32906, 8,0,'A |cFF00FFFFLifebinder''s Gift|r begins to grow!',41,0,100,0,0,0,'Freya EMOTE_LIFEBINDERS_GIFT'),
(32906, 9,0,'Allies of Nature have appeared!',41,0,100,0,0,0,'Freya EMOTE_ALLIES_OF_NATURE'),
(32906,10,0,'Freya begins to cast |cFFFF0000Ground Tremor!|r',41,0,100,0,0,0,'Freya EMOTE_GROUND_TREMOR'),
(32906,11,0,'Freya casts |cFF00FF00Strengthened Iron Roots!|r',41,0,100,0,0,0,'Freya EMOTE_IRON_ROOTS'),
-- Elder Ironbranch
(32913,0,0,'Mortals have no place here!',14,0,100,0,0,15493,'Elder Ironbranch SAY_AGGRO'),
(32913,1,0,'I return you whence you came!',14,0,100,0,0,15494,'Elder Ironbranch SAY_SLAY_1'),
(32913,1,1,'BEGONE!',14,0,100,0,0,15495,'Elder Ironbranch SAY_SLAY_2'),
(32913,2,0,'Freya! They come for you.',14,0,100,0,0,15496,'Elder Ironbranch SAY_DEATH'),
-- Elder Stonebark
(32914,0,0,'This place will serve as your graveyard.',14,0,100,0,0,15500,'Elder Stonebark SAY_AGGRO'),
(32914,1,0,'<Angry roar>',14,0,100,0,0,15501,'Elder Stonebark SAY_SLAY_1'),
(32914,1,1,'Such a waste.',14,0,100,0,0,15502,'Elder Stonebark SAY_SLAY_2'),
(32914,2,0,'Matron, flee! They are ruthless....',14,0,100,0,0,15503,'Elder Stonebark SAY_DEATH'),
-- Elder Brightleaf
(32915,0,0,'Matron, the Conservatory has been breached!',14,0,100,0,0,15483,'Elder Brightleaf SAY_AGGRO'),
(32915,1,0,'Fertilizer.',14,0,100,0,0,15485,'Elder Brightleaf SAY_SLAY_1'),
(32915,1,1,'Your corpse will nourish the soil!',14,0,100,0,0,15486,'Elder Brightleaf SAY_SLAY_2'),
(32915,2,0,'Matron, one has fallen!',14,0,100,0,0,15487,'Elder Brightleaf SAY_DEATH'),
-- Hodir
(32845,0,0,'You will suffer for this trespass!',14,0,100,0,0,15552,'Hodir SAY_AGGRO'),
(32845,1,0,'Tragic. To come so far, only to fail.',14,0,100,0,0,15553,'Hodir SAY_SLAY_1'),
(32845,1,1,'Welcome to the endless winter.',14,0,100,0,0,15554,'Hodir SAY_SLAY_2'),
(32845,2,0,'Winds of the north consume you!',14,0,100,0,0,15555,'Hodir SAY_FLASH_FREEZE'),
(32845,3,0,'%s roars furious.',16,0,100,0,0,15556,'Hodir SAY_STALACTITE'),
(32845,4,0,'I... I am released from his grasp... at last.',14,0,100,0,0,15557,'Hodir SAY_DEATH'),
(32845,5,0,'ENOUGH! This ends now!',14,0,100,0,0,15558,'Hodir SAY_BERSERK'),
(32845,6,0,'%s shatters the Rare Cache of Hodir!',16,0,100,0,0,0,'Hodir SAY_HARD_MODE_MISSED'),
(32845,7,0,'%s begins to cast Flash Freeze!',41,0,100,0,0,0,'Hodir - EMOTE_FREEZE'),
(32845,8,0,'%s gains Frozen Blows!',41,0,100,0,0,0,'Hodir - EMOTE_BLOW'),
-- Ignis
(33118,0,0,'Insolent whelps! Your blood will temper the weapons used to reclaim this world!',14,0,100,0,0,15564,'Ignis SAY_AGGRO'),
(33118,1,0,'Arise, soldiers of the iron crucible! The Makers'' will be done!',14,0,100,0,0,15565,'Ignis SAY_SUMMON'),
(33118,2,0,'I will burn away your impurities!',14,0,100,0,0,15566,'Ignis SAY_SLAG_POT'),
(33118,3,0,'Let the inferno consume you!',14,0,100,0,0,15567,'Ignis SAY_SCORCH_1'),
(33118,3,1,'BURN! Burn in the Maker''s fire!',14,0,100,0,0,15568,'Ignis SAY_SCORCH_2'),
(33118,4,0,'More scraps for the scrapheap!',14,0,100,0,0,15569,'Ignis SAY_SLAY_1'),
(33118,4,1,'Your bones will serve as kindling!',14,0,100,0,0,15570,'Ignis SAY_SLAY_2'),
(33118,5,0,'Let it be finished!',14,0,100,0,0,15571,'Ignis SAY_BERSERK'),
(33118,6,0,'I. Have. Failed.',14,0,100,0,0,15572,'Ignis SAY_DEATH'),
(33118,7,0,'%s begins to cast Flame Jets!',41,0,100,0,0,0,'Ignis EMOTE_JETS'),
-- Kologarn
(32930,0,0,'None shall pass!',14,0,100,0,0,15586,'Kologarn SAY_AGGRO'),
(32930,1,0,'KOL-THARISH!',14,0,100,0,0,15587,'Kologarn SAY_SLAY_1'),
(32930,1,1,'YOU FAIL!',14,0,100,0,0,15588,'Kologarn SAY_SLAY_2'),
(32930,2,0,'Just a scratch!',14,0,100,0,0,15589,'Kologarn SAY_LEFT_ARM_GONE'),
(32930,3,0,'Only a flesh wound!',14,0,100,0,0,15590,'Kologarn SAY_RIGHT_ARM_GONE'),
(32930,4,0,'OBLIVION!',14,0,100,0,0,15591,'Kologarn SAY_SHOCKWAVE'),
(32930,5,0,'I will squeeze the life from you!',14,0,100,0,0,15592,'Kologarn SAY_GRAB_PLAYER'),
(32930,6,0,'Master, they come....',14,0,100,0,0,15593,'Kologarn SAY_DEATH'),
(32930,7,0,'I am invincible!',14,0,100,0,0,15594,'Kologarn SAY_BERSERK'),
(32930,8,0,'Kologarn casts Stone Grip!',41,0,100,0,0,15592,'Kologarn EMOTE_STONE_GRIP'),
-- Expedition Commander
(33210,0,0,'Welcome, champions! All of our attempts at grounding her have failed. We could use a hand in bring her down with these harpoon guns.',12,0,100,0,0,15647,'Expedition Commander SAY_INTRO'),
(33210,1,0,'Move quickly! She won''t remain grounded for long!',14,0,100,0,0,15648,'Expedition Commander SAY_GROUND_PHASE'),
(33210,2,0,'Be on the lookout! Mole machines will be surfacing soon with those nasty Iron dwarves aboard!',14,0,100,0,0,0,'Expedition Commander SAY_AGGRO_2'),
-- Expedition Engineer
(33287,0,0,'Give us a moment to prepare to build the turrets.',14,0,100,0,0,0,'Expedition Engineer SAY_AGGRO_1'),
(33287,1,0,'Ready to move out, keep those dwarves off of our backs!',14,0,100,0,0,0,'Expedition Engineer SAY_AGGRO_3'),
(33287,2,0,'Fires out! Let''s rebuild those turrets!',14,0,100,0,0,0,'SAY_TURRETS'),
-- Razorscale
(33186,0,0,'%s is grounded permanently!',41,0,100,0,0,0,'Razorscale EMOTE_PERMA'),
(33186,1,0,'%s takes a deep breath...',41,0,100,0,0,0,'Razorscale EMOTE_BREATH'),
-- Razorscale Controller
(33233,0,0,'Harpoon Turret is ready for use!',41,0,100,0,0,0,'Razorscale Controller EMOTE_HARPOON'),
-- General Vezax
(33271,0,0,'Your destruction will herald a new age of suffering!',14,0,100,0,0,15542,'General Vezax SAY_AGGRO'),
(33271,1,0,'You thought to stand before the legions of death... and survive?',14,0,100,0,0,15543,'General Vezax SAY_SLAY_1'),
(33271,1,1,'Defiance... a flaw of mortality.',14,0,100,0,0,15544,'General Vezax SAY_SLAY_2'),
(33271,2,0,'The black blood of Yogg-Saron courses through me! I. AM. UNSTOPPABLE!',14,0,100,0,0,15545,'General Vezax SAY_SURGE_OF_DARKNESS'),
(33271,3,0,'Oh, what horrors await....',14,0,100,0,0,15546,'General Vezax SAY_DEATH'),
(33271,4,0,'Your defeat was inevitable!',14,0,100,0,0,15547,'General Vezax SAY_BERSERK'),
(33271,5,0,'Behold, now! Terror, absolute!',14,0,100,0,0,15548,'General Vezax SAY_HARDMODE'),
(33271,6,0,'The saronite vapors mass and swirl violently, merging into a monstrous form!',41,0,100,0,0,0,'General Vezax - EMOTE_ANIMUS'),
(33271,7,0,'A saronite barrier appears around General Vezax!',41,0,100,0,0,0,'General Vezax - EMOTE_BARRIER'),
(33271,8,0,'%s roars and surges with dark might!',41,0,100,0,0,0,'General Vezax - EMOTE_SURGE_OF_DARKNESS'),
-- Saronite Vapor
(33488,0,0,'A cloud of saronite vapors coalesces nearby!',41,0,100,0,0,0,'Saronite Vapor - EMOTE_VAPORS'),
-- XT-002 Deconstructor
(33293, 0,0,'New toys? For me? I promise I won''t break them this time!',14,0,100,0,0,15724,'XT-002 Deconstructor SAY_AGGRO'),
(33293, 1,0,'So tired. I will rest for just a moment!',14,0,100,0,0,15725,'XT-002 Deconstructor SAY_HEART_OPENED'),
(33293, 2,0,'I''m ready to play!',14,0,100,0,0,15726,'XT-002 Deconstructor SAY_HEART_CLOSED'),
(33293, 3,0,'NO! NO! NO! NO! NO!',14,0,100,0,0,15727,'XT-002 Deconstructor SAY_TYMPANIC_TANTRUM'),
(33293, 4,0,'I... I think I broke it.',14,0,100,0,0,15728,'XT-002 Deconstructor SAY_SLAY_1'),
(33293, 4,1,'I guess it doesn''t bend that way.',14,0,100,0,0,15729,'XT-002 Deconstructor SAY_SLAY_2'),
(33293, 5,0,'I''m tired of these toys. I don''t want to play anymore!',14,0,100,0,0,15730,'XT-002 Deconstructor SAY_BERSERK'),
(33293, 6,0, 'You are bad... Toys... Very... Baaaaad ',14,0,100,0,0,15731,'XT-002 Deconstructor SAY_DEATH'),
(33293, 7,0,'Time for a new game! My old toys will fight my new toys!',14,0,100,0,0,15732,'XT-002 Deconstructor SAY_SUMMON'),
(33293, 8,0,'%s''s heart is exposed and leaking energy.',41,0,100,0,0,0,'XT-002 Deconstructor EMOTE_HEART_OPENED'),
(33293, 9,0,'%s''s heart is severed from his body.',41,0,100,0,0,0,'XT-002 Deconstructor EMOTE_HEART_CLOSED'),
(33293,10,0,'%s begins to cause the earth to quake.',41,0,100,0,0,0,'XT-002 Deconstructor EMOTE_TYMPANIC_TANTRUM'),
(33293,11,0,'%s consumes a scrap bot to repair himself!',41,0,100,0,0,0,'XT-002 Deconstructor EMOTE_SCRAPBOT'),
-- Thorim
(32865, 0,0,'Interlopers! You mortals who dare to interfere with my sport will pay... Wait--you...',14,0,100,0,0,15733,'Thorim SAY_AGGRO_1'),
(32865, 0,1,'I remember you... In the mountains... But you... what is this? Where am--',14,0,100,0,0,15734,'Thorim SAY_AGGRO_2'),
(32865, 1,0,'Behold the power of the storms and despair!',14,0,100,0,0,15735,'Thorim SAY_SPECIAL_1'),
(32865, 2,0,'Do not hold back! Destroy them!',14,0,100,0,0,15736,'Thorim SAY_SPECIAL_2'),
(32865, 3,0,'Have you begun to regret your intrusion?',14,0,100,0,0,15737,'Thorim SAY_SPECIAL_3'),
(32865, 4,0,'Impertinent whelps, you dare challenge me atop my pedestal? I will crush you myself!',14,0,100,0,0,15738,'Thorim SAY_JUMPDOWN'),
(32865, 5,0,'Can''t you at least put up a fight!?',14,0,100,0,0,15739,'Thorim SAY_SLAY_1'),
(32865, 5,1,'Pathetic.',14,0,100,0,0,15740,'Thorim SAY_SLAY_2'),
(32865, 6,0,'My patience has reached its limit!',14,0,100,0,0,15741,'Thorim SAY_BERSERK'),
(32865, 7,0,'Failures! Weaklings!',14,0,100,0,0,15742,'Thorim SAY_WIPE'),
(32865, 8,0,'Stay your arms! I yield!',14,0,100,0,0,15743,'Thorim SAY_DEATH'),
(32865, 9,0,'I feel as though I am awakening from a nightmare, but the shadows in this place yet linger.',14,0,100,0,0,15744,'Thorim SAY_END_NORMAL_1'),
(32865,10,0,'Sif... was Sif here? Impossible--she died by my brother''s hand. A dark nightmare indeed....',14,0,100,0,0,15745,'Thorim SAY_END_NORMAL_2'),
(32865,11,0,'I need time to reflect.... I will aid your cause if you should require it. I owe you at least that much. Farewell.',14,0,100,0,0,15746,'Thorim SAY_END_NORMAL_3'),
(32865,12,0,'You! Fiend! You are not my beloved! Be gone!',14,0,100,0,0,15747,'Thorim SAY_END_HARD_1'),
(32865,13,0,'Behold the hand behind all the evil that has befallen Ulduar, left my kingdom in ruins, corrupted my brother, and slain my wife.',14,0,100,0,0,15748,'Thorim SAY_END_HARD_2'),
(32865,14,0,'And now it falls to you, champions, to avenge us all. The task before you is great, but I will lend you my aid as I am able. You must prevail.',14,0,100,0,0,15749,'Thorim SAY_END_HARD_3');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=64604;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,64604,0,0,31,0,4,0,0,0,0,0,'','Freya - Nature Bomb');
