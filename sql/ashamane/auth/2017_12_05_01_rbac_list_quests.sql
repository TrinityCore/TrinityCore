DELETE FROM rbac_linked_permissions WHERE id = 197 AND linkedId = 2003;
DELETE FROM rbac_permissions WHERE id = 2003;

INSERT INTO rbac_permissions VALUES (2003, "Command: .list quests");
INSERT INTO rbac_linked_permissions VALUES (197, 2003);
