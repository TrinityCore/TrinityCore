-- 
UPDATE `npc_text` SET `text0_1`="From this dock, The Bravery travels back and forth between Stormwind and Auberdine.", `BroadcastTextID0`=0 WHERE `ID`=13321;

DELETE FROM `npc_text_locale` WHERE `ID`=13321;
INSERT INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`) VALUES
(13321,"frFR","","Depuis ce quai, la Bravoure fait l'aller-retour entre Hurlevent et Auberdine."),
(13321,"esES","","Desde este muelle, El Valentía hace el viaje de ida y vuelta entre Ventormenta y Auberdine."),
(13321,"esMX","","Desde este muelle, El Valentía hace el viaje de ida y vuelta entre Ventormenta y Auberdine."),
(13321,"deDE","","Von diesem Dock aus fährt die Bravado zwischen Sturmwind und Auberdine hin und her.");
