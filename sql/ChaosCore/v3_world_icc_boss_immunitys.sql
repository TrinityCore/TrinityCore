SET @Lord_Marrowgar := 36612;
SET @Lord_Marrowgar10H := (SELECT `difficulty_entry_2` FROM `creature_template` WHERE `entry` = @Lord_Marrowgar);
SET @Lord_Marrowgar25 := (SELECT `difficulty_entry_1` FROM `creature_template` WHERE `entry` = @Lord_Marrowgar);
SET @Lord_Marrowgar25H := (SELECT `difficulty_entry_3` FROM `creature_template` WHERE `entry` = @Lord_Marrowgar);
SET @Lady_Deathwhisper := 36855;
SET @Lady_Deathwhisper10H := (SELECT `difficulty_entry_2` FROM `creature_template` WHERE `entry` = @Lady_Deathwhisper);
SET @Lady_Deathwhisper25 := (SELECT `difficulty_entry_1` FROM `creature_template` WHERE `entry` = @Lady_Deathwhisper);
SET @Lady_Deathwhisper25H := (SELECT `difficulty_entry_3` FROM `creature_template` WHERE `entry` = @Lady_Deathwhisper);
SET @Saurfang10N := 37813;
SET @Saurfang25N := (SELECT `difficulty_entry_2` FROM `creature_template` WHERE `entry` = @Saurfang10N);
SET @Saurfang10H := (SELECT `difficulty_entry_1` FROM `creature_template` WHERE `entry` = @Saurfang10N);
SET @Saurfang25H := (SELECT `difficulty_entry_3` FROM `creature_template` WHERE `entry` = @Saurfang10N);
SET @Festergut := 36626;
SET @Festergut10H := (SELECT `difficulty_entry_2` FROM `creature_template` WHERE `entry` = @Festergut);
SET @Festergut25 := (SELECT `difficulty_entry_1` FROM `creature_template` WHERE `entry` = @Festergut);
SET @Festergut25H := (SELECT `difficulty_entry_3` FROM `creature_template` WHERE `entry` = @Festergut);
SET @Rotface := 36627;
SET @Rotface10H := (SELECT `difficulty_entry_2` FROM `creature_template` WHERE `entry` = @Rotface);
SET @Rotface25 := (SELECT `difficulty_entry_1` FROM `creature_template` WHERE `entry` = @Rotface);
SET @Rotface25H := (SELECT `difficulty_entry_3` FROM `creature_template` WHERE `entry` = @Rotface);
SET @Professor_Putricide := 36678;
SET @Professor_Putricide10H := (SELECT `difficulty_entry_2` FROM `creature_template` WHERE `entry` = @Professor_Putricide);
SET @Professor_Putricide25 := (SELECT `difficulty_entry_1` FROM `creature_template` WHERE `entry` = @Professor_Putricide);
SET @Professor_Putricide25H := (SELECT `difficulty_entry_3` FROM `creature_template` WHERE `entry` = @Professor_Putricide);
SET @Prince_Valanar := 37970;
SET @Prince_Valanar10H := (SELECT `difficulty_entry_2` FROM `creature_template` WHERE `entry` = @Prince_Valanar);
SET @Prince_Valanar25 := (SELECT `difficulty_entry_1` FROM `creature_template` WHERE `entry` = @Prince_Valanar);
SET @Prince_Valanar25H := (SELECT `difficulty_entry_3` FROM `creature_template` WHERE `entry` = @Prince_Valanar);
SET @Blood_Queen_Lanathel := 37955;
SET @Blood_Queen_Lanathel10H := (SELECT `difficulty_entry_2` FROM `creature_template` WHERE `entry` = @Blood_Queen_Lanathel);
SET @Blood_Queen_Lanathel25 := (SELECT `difficulty_entry_1` FROM `creature_template` WHERE `entry` = @Blood_Queen_Lanathel);
SET @Blood_Queen_Lanathel25H := (SELECT `difficulty_entry_3` FROM `creature_template` WHERE `entry` = @Blood_Queen_Lanathel);
SET @Sindragosa := 36853;
SET @Sindragosa10H := (SELECT `difficulty_entry_2` FROM `creature_template` WHERE `entry` = @Sindragosa);
SET @Sindragosa25 := (SELECT `difficulty_entry_1` FROM `creature_template` WHERE `entry` = @Sindragosa);
SET @Sindragosa25H := (SELECT `difficulty_entry_3` FROM `creature_template` WHERE `entry` = @Sindragosa);
SET @Lich_King := 36597;
SET @Lich_King10H := (SELECT `difficulty_entry_2` FROM `creature_template` WHERE `entry` = @Lich_King);
SET @Lich_King25 := (SELECT `difficulty_entry_1` FROM `creature_template` WHERE `entry` = @Lich_King);
SET @Lich_King25H := (SELECT `difficulty_entry_3` FROM `creature_template` WHERE `entry` = @Lich_King);

-- mechanic immunity fixes
UPDATE creature_template SET mechanic_immune_mask = (	1|	 #MECHANIC_CHARM	 (charmed)
                                                        2|	 #MECHANIC_DISORIENTED	 (disoriented)
                                                        4|	 #MECHANIC_DISARM	 (disarmed)
                                                        8|	 #MECHANIC_DISTRACT	 (distracted)
                                                        16|	 #MECHANIC_FEAR	 (fleeing)
                                                        32|	 #MECHANIC_GRIP	 (gripped)	 Deathgrip and thunderstorm etc
                                                        64|	 #MECHANIC_ROOT	 (rooted)
                                                        128|	 #MECHANIC_PACIFY	 (slowed)
                                                        256|	 #MECHANIC_SILENCE	 (silenced)
                                                        512|	 #MECHANIC_SLEEP	 (asleep)
                                                        1024|	 #MECHANIC_SNARE	 (snared)
                                                        2048|	 #MECHANIC_STUN	 (stunned)
                                                        4096|	 #MECHANIC_FREEZE	 (frozen)
                                                        8192|	 #MECHANIC_KNOUCKOUT	 (incapacitated)
                                                        #16384|	 #MECHANIC_BLEED	 (bleeding)
                                                        #32768|	 #MECHANIC_BANDAGE	 (healing)
                                                        65536|	 #MECHANIC_POLYMORPH	 (polymorphed)
                                                        131072|	 #MECHANIC_BANISH	 (banished)
                                                        #262144|	 #MECHANIC_SHIELD	 (shielded)
                                                        524288|	 #MECHANIC_SHACKLE	 (shackled)
                                                        #1048576|	#MECHANIC_MOUNT	 (mounted)
                                                        #2097152|	#MECHANIC_INFECTED	 (infected)	 Diseases and devouring plague etc
                                                        4194304|	#MECHANIC_TURN	 (turned)	 Turn Evil etc.
                                                        8388608|	#MECHANIC_HORROR	 (horrified)	 Death Coil (warlock) etc.
                                                        #16777216|	#MECHANIC_INVULNERABILITY	(invulnerable)
                                                        33554432|	#MECHANIC_INTERRUPT	 (interruped)
                                                        67108864)	#MECHANIC_DAZE	 (dazed)
                                                        #134217728|	#MECHANIC_DISCOVERY	 (discovery)
                                                        #268435456|	#MECHANIC_IMMUNE_SHIELD	 (invulnerable)
                                                        #536870912|	#MECHANIC_SAPPED	 (sapped)
                                                        #1073741824)	#MECHANIC_ENRAGED	 (enraged)
                                                        WHERE entry IN (
    @Lord_Marrowgar,@Lady_Deathwhisper,@Festergut,@Rotface,@Professor_Putricide,@Prince_Valanar,@Blood_Queen_Lanathel,@Sindragosa,@Lich_King, -- 10normal mode
    @Lord_Marrowgar25,@Lady_Deathwhisper25,@Festergut25,@Rotface25,@Professor_Putricide25,@Prince_Valanar25,@Blood_Queen_Lanathel25,@Sindragosa25,@Lich_King25, -- 25normal mode
    @Lord_Marrowgar10H,@Lady_Deathwhisper10H,@Festergut10H,@Rotface10H,@Professor_Putricide10H,@Prince_Valanar10H,@Blood_Queen_Lanathel10H,@Sindragosa10H,@Lich_King10H, -- 10hero mode
    @Lord_Marrowgar25H,@Lady_Deathwhisper25H,@Festergut25H,@Rotface25H,@Professor_Putricide25H,@Prince_Valanar25H,@Blood_Queen_Lanathel25H,@Sindragosa25H,@Lich_King25H); -- 25hero mode