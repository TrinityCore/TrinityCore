UPDATE areatrigger SET ScriptName = "" WHERE guid IN (11, 12, 13, 14);

DELETE FROM areatrigger_teleport WHERE ID IN (-11, -12, -13, -14);
INSERT INTO areatrigger_teleport VALUES
(-11, 5334, "Darkheart Thicket entrance"),
(-12, 5343, "Darkheart Thicket exit"),
(-13, 5100, "Eye of Azshara entrance"),
(-14, 5114, "Eye of Azshara exit");
