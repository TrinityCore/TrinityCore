DELETE FROM battleground_template WHERE ID IN (1014, 2);
+INSERT INTO battleground_template VALUES
+(1014, 7051, 7050, 75, 1, '', 'Warsong Gulch');
+
+DELETE FROM gameobject_template_addon WHERE entry IN (227741, 227740, 227745, 227744);
+INSERT INTO gameobject_template_addon VALUES
+(227741, 1995, 32, 0, 0, 0, 0),
+(227740, 1997, 32, 0, 0, 0, 0),
+(227745, 1913, 0, 0, 0, 0, 0),
+(227744, 1913, 0, 0, 0, 0, 0);
