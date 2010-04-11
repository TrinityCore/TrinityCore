DELETE FROM `script_texts` WHERE `entry` <= -1601000 and `entry` >= -1601022;
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES

-- Anub'arak
('29120', '-1601000', 'Eternal aggony awaits you!', null, null, null, null, null, null, null, null, '14054', '1', '0', '0', ''),
('29120', '-1601001', 'Soon, the Master\'s voice will call to you.', null, null, null, null, null, null, null, null, '14057', '1', '0', '0', ''),
('29120', '-1601002', 'You have made your choice.', null, null, null, null, null, null, null, null, '14056', '1', '0', '0', ''),
('29120', '-1601003', 'You shall experience my torment, first-hand!', null, null, null, null, null, null, null, null, '14055', '1', '0', '0', ''),
('29120', '-1601004', 'Ahhh... RAAAAAGH! Never thought... I would be free of him...', null, null, null, null, null, null, null, null, '14069', '1', '0', '0', ''),
('29120', '-1601005', 'Your armor is useless againts my locusts.', null, null, null, null, null, null, null, null, '14060', '1', '0', '0', ''),
('29120', '-1601006', 'Uunak-hissss tik-k-k-k-k!', null, null, null, null, null, null, null, null, '14067', '1', '0', '0', ''),
('29120', '-1601007', 'The pestilence upon you!', null, null, null, null, null, null, null, null, '14068', '1', '0', '0', ''),
('29120', '-1601008', 'Auum na-l ak-k-k-k, isshhh.', null, null, null, null, null, null, null, null, '14058', '1', '0', '0', ''),
('29120', '-1601009', 'Come forth my brethren! Feast on their flesh.', null, null, null, null, null, null, null, null, '14059', '1', '0', '0', ''),
('29120', '-1601010', 'I was king of this empire once\, long ago. In life I stood as champion. In death I returned as conqueror. Now I protect the kingdom once more. Ironic\, yes? ', null, null, null, null, null, null, null, null, '14053', '1', '0', '0', ''),

-- Kirkthir
('28684', '-1601011', 'This kingdom belongs to the Scourge! Only the dead may enter.', null, null, null, null, null, null, null, null, '14075', '1', '0', '0', ''),
('28684', '-1601012', 'You were foolish to come.', null, null, null, null, null, null, null, null, '14077', '1', '0', '0', ''),
('28684', '-1601013', 'As Anub\'Arak commands!', null, null, null, null, null, null, null, null, '14078', '1', '0', '0', ''),
('28684', '-1601014', 'I should be grateful. But I long ago lost the capacity.', null, null, null, null, null, null, null, null, '14087', '1', '0', '0', ''),
('28684', '-1601015', 'They hunger.', null, null, null, null, null, null, null, null, '14085', '1', '0', '0', ''),
('28684', '-1601016', 'Dinner time\, my pets.', null, null, null, null, null, null, null, null, '14086', '1', '0', '0', ''),
('28684', '-1601017', 'Keep an eye on the tunnel. We must not let anyone through!', null, null, null, null, null, null, null, null, '14082', '1', '0', '0', ''),
('28684', '-1601018', 'I hear footsteps. Be on your guard.', null, null, null, null, null, null, null, null, '14083', '1', '0', '0', ''),
('28684', '-1601019', 'I sense the living. Be ready.', null, null, null, null, null, null, null, null, '14084', '1', '0', '0', ''),
('28684', '-1601020', 'We are besieged. Strike out and bring back their corpses!', null, null, null, null, null, null, null, null, '14079', '1', '0', '0', ''),
('28684', '-1601021', 'We must hold the gate. Attack! Tear them limb from limb!', null, null, null, null, null, null, null, null, '14080', '1', '0', '0', ''),
('28684', '-1601022', 'The gate must be protected at all costs. Rip them to shreds!', null, null, null, null, null, null, null, null, '14081', '1', '0', '0', '');
