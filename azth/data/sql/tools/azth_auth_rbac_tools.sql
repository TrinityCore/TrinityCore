# TOOLS:
#
# Query to check linked permission giving a permission id
select * from rbac_permissions WHERE id IN (select linkedId FROM rbac_linked_permissions WHERE id = 198)

# Show azeroth roles
select * from rbac_permissions WHERE id >= 100000

# How to extract commands and add to this file:
SELECT CONCAT("(100001,",id,"), #",`name`) FROM rbac_permissions WHERE NAME LIKE "%Command: lookup%" 

# create readable list of all permissions
SELECT CONCAT("-- ",NAME) FROM rbac_permissions ORDER BY NAME,ID



#
# SINGLE USER SEARCH
# Categoria del permesso (ultima da cui eredita) | Id del permesso | Nome del permesso

#Query che passando %IDACCOUNT% id dell’account player ritorna tutti i comandi abilitati per quel player. La tupla è nella forma

SET @IDACCOUNT = 624;

SELECT DISTINCT t.id AS user_id, r.id AS perm_id, r.name FROM (
	SELECT a.id AS ID, IFNULL(e.linkedId, IFNULL(d.linkedId, IFNULL(c.linkedId, IFNULL(b.linkedId, a.linkedId)))) LINK FROM rbac_linked_permissions a LEFT JOIN rbac_linked_permissions b ON (a.linkedId = b.id) LEFT JOIN rbac_linked_permissions c ON (b.linkedId = c.id) LEFT JOIN rbac_linked_permissions d ON (c.linkedId = d.id) LEFT JOIN rbac_linked_permissions e ON (d.linkedId = e.id) 
) t JOIN rbac_permissions r ON (LINK = r.id) WHERE t.id IN (
	SELECT rbac_account_permissions.permissionId FROM (SELECT id FROM account_access WHERE id = @IDACCOUNT ) account JOIN rbac_account_permissions ON (account.id = rbac_account_permissions.accountId)
		UNION 
	SELECT rbac_default_permissions.permissionId FROM (SELECT gmlevel FROM account_access WHERE id = @IDACCOUNT ) account JOIN rbac_default_permissions ON (account.gmlevel = rbac_default_permissions.secId)
)









#
# ROLE SEARCH
# 

SET @ROLE = 100010;

SELECT DISTINCT t.id as user_id, r.id as perm_id, r.name FROM (
select a.id as ID, IFNULL(e.linkedId, IFNULL(d.linkedId, IFNULL(c.linkedId, IFNULL(b.linkedId, a.linkedId)))) LINK FROM rbac_linked_permissions a left join rbac_linked_permissions b ON (a.linkedId = b.id) left join rbac_linked_permissions c ON (b.linkedId = c.id) left join rbac_linked_permissions d ON (c.linkedId = d.id) left join rbac_linked_permissions e ON (d.linkedId = e.id)
) t JOIN rbac_permissions r ON (LINK = r.id)
WHERE t.id = @ROLE

#
# ROLE SEARCH depth = 10
# 

SET @ROLE = 100010;

SELECT DISTINCT t.id AS user_id, r.id AS perm_id, r.name FROM (
SELECT a.id AS ID, 
    IFNULL(i.linkedId,
    IFNULL(h.linkedId,
    IFNULL(g.linkedId,
    IFNULL(f.linkedId,
    IFNULL(e.linkedId, 
    IFNULL(d.linkedId, 
    IFNULL(c.linkedId, 
    IFNULL(b.linkedId, a.linkedId))))))))
    LINK FROM rbac_linked_permissions a 
    LEFT JOIN rbac_linked_permissions b ON (a.linkedId = b.id) 
    LEFT JOIN rbac_linked_permissions c ON (b.linkedId = c.id) 
    LEFT JOIN rbac_linked_permissions d ON (c.linkedId = d.id) 
    LEFT JOIN rbac_linked_permissions e ON (d.linkedId = e.id) 
    LEFT JOIN rbac_linked_permissions f ON (e.linkedId = f.id) 
    LEFT JOIN rbac_linked_permissions g ON (f.linkedId = g.id) 
    LEFT JOIN rbac_linked_permissions h ON (g.linkedId = h.id) 
    LEFT JOIN rbac_linked_permissions i ON (h.linkedId = i.id)

) t JOIN rbac_permissions r ON (LINK = r.id)
WHERE t.id = @ROLE



