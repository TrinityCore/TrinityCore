UPDATE areatrigger SET ScriptName = "" WHERE guid IN (11, 12);

DELETE FROM areatrigger_teleport WHERE ID IN (-11, -12);
INSERT INTO areatrigger_teleport VALUES
(-11, 5334, "Darkheart Thicket entrance"),
(-12, 5343, "Darkheart Thicket exit");
