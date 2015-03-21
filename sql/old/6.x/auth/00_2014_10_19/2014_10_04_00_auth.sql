DELETE FROM `battlenet_components` WHERE `Build`=18973 AND `Program`!='Bnet';
DELETE FROM `battlenet_components` WHERE `Build`=37165 AND `Program`='Bnet';
INSERT INTO `battlenet_components` VALUES
('Bnet','Win',37165),
('Bnet','Wn64',37165),
('WoW','base',18973),
('WoWB','Win',18973),
('WoWB','Wn64',18973);
