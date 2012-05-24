DELETE FROM command WHERE name IN("instance getdata", "instance setdata");
INSERT INTO command (name, security, help) VALUES
("instance getdata", 3, "Syntax: .instance getdata #dataIndex

Attempts to call an InstanceScript's GetData and prints you the value. Will work on the selected player's map, or on your map as a fallback."),
("instance setdata", 3, "Syntax: .instance setdata #dataIndex #newValue

Calls InstanceScript::GetData and sets data identified by #dataIndex to #newValue. Will work on the selected player's map, or on your map as a fallback.");
