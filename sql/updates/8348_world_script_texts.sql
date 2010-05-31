-- Skadi the Ruthless voice
DELETE FROM `script_texts` WHERE `npc_entry`=26693;
INSERT INTO `script_texts` VALUES 
(26693,-1575004, "What mongrels dare intrude here? Look alive, my brothers! A feast for the one that brings me their heads!" ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13497,1,0,0, "Skadi - SAY_AGGRO"),
(26693,-1575005, "Not so brash now, are you?" ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13504,1,0,0, "Skadi - SAY_KILL_1"),
(26693,-1575006, "I'll mount your skull from the highest tower!" ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13505,1,0,0, "Skadi - SAY_KILL_2"),
(26693,-1575007, "%s in within range of the harpoon launchers!" ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0, "Skadi - EMOTE_RANGE"),
(26693,-1575008, "ARGH! You call that... an attack? I'll... show... aghhhh..." ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13506,1,0,0, "Skadi - SAY_DEATH"),
(26693,-1575009, "%s in within range of the harpoon launchers!" ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,3,0,0, "Skadi - EMOTE_RANGE"),
(26693,-1575010, "You motherless knaves! Your corpses will make fine morsels for my new drake!" ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13507,1,0,0, "Skadi - SAY_DRAKE_DEATH"),
(26693,-1575011, "Sear them to the bone!" ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13498,1,0,0, "Skadi - SAY_DRAKE_BREATH_1"),
(26693,-1575012, "Go now! Leave nothing but ash in your wake!" ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13499,1,0,0, "Skadi - SAY_DRAKE_BREATH_2"),
(26693,-1575013, "Cleanse our sacred halls with flame!" ,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,13500,1,0,0, "Skadi - SAY_DRAKE_BREATH_3");
