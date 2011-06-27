/*
 Navicat Premium Data Transfer

 Source Server         : test-sql
 Source Server Type    : SQLite
 Source Server Version : 3006022
 Source Database       : main

 Target Server Type    : SQLite
 Target Server Version : 3006022
 File Encoding         : utf-8

 Date: 03/10/2011 01:45:55 AM
*/

-- ----------------------------
--  Table structure for "global_stats"
-- ----------------------------
DROP TABLE IF EXISTS "global_stats";
CREATE TABLE "global_stats" (
	 "id" integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	 "key" text NOT NULL,
	 "value" integer NOT NULL
);

-- ----------------------------
--  Table structure for "group_permissions"
-- ----------------------------
DROP TABLE IF EXISTS "group_permissions";
CREATE TABLE "group_permissions" (
	 "id" integer NOT NULL,
	 "group_id" integer NOT NULL,
	 "permission_id" integer NOT NULL,
	PRIMARY KEY("id")
);

-- ----------------------------
--  Records of "group_permissions"
-- ----------------------------
BEGIN;
INSERT INTO "group_permissions" VALUES ('1', '1', '1');
INSERT INTO "group_permissions" VALUES ('2', '1', '2');
INSERT INTO "group_permissions" VALUES ('3', '1', '3');
INSERT INTO "group_permissions" VALUES ('4', '1', '4');
INSERT INTO "group_permissions" VALUES ('5', '1', '5');
INSERT INTO "group_permissions" VALUES ('6', '1', '6');
INSERT INTO "group_permissions" VALUES ('7', '1', '7');
INSERT INTO "group_permissions" VALUES ('8', '1', '8');
INSERT INTO "group_permissions" VALUES ('9', '1', '9');
INSERT INTO "group_permissions" VALUES ('10', '1', '10');
INSERT INTO "group_permissions" VALUES ('11', '1', '11');
INSERT INTO "group_permissions" VALUES ('12', '1', '12');
INSERT INTO "group_permissions" VALUES ('13', '1', '13');
INSERT INTO "group_permissions" VALUES ('14', '4', '14');
INSERT INTO "group_permissions" VALUES ('15', '1', '15');
INSERT INTO "group_permissions" VALUES ('16', '1', '16');
INSERT INTO "group_permissions" VALUES ('17', '1', '17');
INSERT INTO "group_permissions" VALUES ('18', '1', '18');
INSERT INTO "group_permissions" VALUES ('19', '1', '19');
INSERT INTO "group_permissions" VALUES ('20', '1', '20');
INSERT INTO "group_permissions" VALUES ('21', '2', '1');
INSERT INTO "group_permissions" VALUES ('22', '2', '2');
INSERT INTO "group_permissions" VALUES ('23', '2', '3');
INSERT INTO "group_permissions" VALUES ('24', '2', '4');
INSERT INTO "group_permissions" VALUES ('25', '2', '5');
INSERT INTO "group_permissions" VALUES ('26', '2', '6');
INSERT INTO "group_permissions" VALUES ('27', '2', '7');
INSERT INTO "group_permissions" VALUES ('28', '2', '8');
INSERT INTO "group_permissions" VALUES ('29', '2', '9');
INSERT INTO "group_permissions" VALUES ('30', '2', '10');
INSERT INTO "group_permissions" VALUES ('31', '2', '11');
INSERT INTO "group_permissions" VALUES ('32', '2', '13');
INSERT INTO "group_permissions" VALUES ('33', '2', '14');
INSERT INTO "group_permissions" VALUES ('34', '2', '15');
INSERT INTO "group_permissions" VALUES ('35', '2', '16');
INSERT INTO "group_permissions" VALUES ('36', '2', '17');
INSERT INTO "group_permissions" VALUES ('37', '2', '18');
INSERT INTO "group_permissions" VALUES ('38', '2', '19');
INSERT INTO "group_permissions" VALUES ('39', '2', '20');
INSERT INTO "group_permissions" VALUES ('40', '3', '1');
INSERT INTO "group_permissions" VALUES ('41', '3', '3');
INSERT INTO "group_permissions" VALUES ('42', '3', '6');
INSERT INTO "group_permissions" VALUES ('43', '3', '9');
INSERT INTO "group_permissions" VALUES ('44', '3', '11');
INSERT INTO "group_permissions" VALUES ('45', '3', '13');
INSERT INTO "group_permissions" VALUES ('46', '3', '14');
INSERT INTO "group_permissions" VALUES ('47', '3', '15');
INSERT INTO "group_permissions" VALUES ('48', '3', '17');
INSERT INTO "group_permissions" VALUES ('49', '3', '18');
INSERT INTO "group_permissions" VALUES ('50', '3', '19');
INSERT INTO "group_permissions" VALUES ('51', '3', '20');
INSERT INTO "group_permissions" VALUES ('52', '4', '1');
INSERT INTO "group_permissions" VALUES ('53', '4', '22');
INSERT INTO "group_permissions" VALUES ('54', '4', '8');
INSERT INTO "group_permissions" VALUES ('55', '4', '3');
INSERT INTO "group_permissions" VALUES ('56', '4', '21');
INSERT INTO "group_permissions" VALUES ('57', '4', '14');
INSERT INTO "group_permissions" VALUES ('58', '4', '9');
INSERT INTO "group_permissions" VALUES ('59', '4', '13');
INSERT INTO "group_permissions" VALUES ('60', '5', '22');
INSERT INTO "group_permissions" VALUES ('61', '5', '8');
INSERT INTO "group_permissions" VALUES ('62', '5', '3');
INSERT INTO "group_permissions" VALUES ('63', '5', '14');
INSERT INTO "group_permissions" VALUES ('64', '1', '21');
INSERT INTO "group_permissions" VALUES ('65', '1', '22');
INSERT INTO "group_permissions" VALUES ('66', '2', '21');
INSERT INTO "group_permissions" VALUES ('67', '2', '22');
INSERT INTO "group_permissions" VALUES ('68', '3', '21');
INSERT INTO "group_permissions" VALUES ('69', '3', '22');
COMMIT;

-- ----------------------------
--  Table structure for "groups"
-- ----------------------------
DROP TABLE IF EXISTS "groups";
CREATE TABLE "groups" (
	 "id" integer NOT NULL,
	 "group_name" text NOT NULL,
	PRIMARY KEY("id")
);

-- ----------------------------
--  Records of "groups"
-- ----------------------------
BEGIN;
INSERT INTO "groups" VALUES ('1', 'Owner');
INSERT INTO "groups" VALUES ('2', 'Leader');
INSERT INTO "groups" VALUES ('3', 'Member');
INSERT INTO "groups" VALUES ('4', 'Regular');
INSERT INTO "groups" VALUES ('5', 'Player');
COMMIT;

-- ----------------------------
--  Table structure for "lastlog"
-- ----------------------------
DROP TABLE IF EXISTS "lastlog";
CREATE TABLE "lastlog" (
	 "id" integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	 "last_log" integer NOT NULL
);

-- ----------------------------
--  Table structure for "options"
-- ----------------------------
DROP TABLE IF EXISTS "options";
CREATE TABLE "options" (
	 "id" integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	 "key" text NOT NULL,
	 "value" text NOT NULL
);

-- ----------------------------
--  Records of "options"
-- ----------------------------
BEGIN;
INSERT INTO "options" VALUES ('1', 'welcome_msg', '^2Welcome to the ^1real world!');
INSERT INTO "options" VALUES ('2', 'welcome_player', '^2Welcome ^1%s ^2to in our arena');
INSERT INTO "options" VALUES ('3', 'not_allowed', '^2%s ^1is not allowed to use the "^2%s" command!');
COMMIT;

-- ----------------------------
--  Table structure for "permissions"
-- ----------------------------
DROP TABLE IF EXISTS "permissions";
CREATE TABLE "permissions" (
	 "id" integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	 "permission" integer NOT NULL,
	 "permission_name" text NOT NULL
);

-- ----------------------------
--  Records of "permissions"
-- ----------------------------
BEGIN;
INSERT INTO "permissions" VALUES ('1', '!admincheck', 'Admincheck');
INSERT INTO "permissions" VALUES ('2', '!ban', 'ban');
INSERT INTO "permissions" VALUES ('3', '!cmd', 'cmd');
INSERT INTO "permissions" VALUES ('4', '!defaultmap', 'default map');
INSERT INTO "permissions" VALUES ('5', '!groups', 'groups');
INSERT INTO "permissions" VALUES ('6', '!kick', 'kick');
INSERT INTO "permissions" VALUES ('7', '!map', 'map');
INSERT INTO "permissions" VALUES ('8', '!nextmap', 'nextmap');
INSERT INTO "permissions" VALUES ('9', '!pl', 'pl');
INSERT INTO "permissions" VALUES ('10', '!playlist', 'playlist');
INSERT INTO "permissions" VALUES ('11', '!rank', 'rank');
INSERT INTO "permissions" VALUES ('12', '!rcon', 'rcon');
INSERT INTO "permissions" VALUES ('13', '!reserved', 'reserved');
INSERT INTO "permissions" VALUES ('14', '!rules', 'rules');
INSERT INTO "permissions" VALUES ('15', '!say', 'say');
INSERT INTO "permissions" VALUES ('16', '!setgroup', 'set group');
INSERT INTO "permissions" VALUES ('17', '!stats', 'stats');
INSERT INTO "permissions" VALUES ('18', '!tempban', 'temp ban');
INSERT INTO "permissions" VALUES ('19', '!top', 'top');
INSERT INTO "permissions" VALUES ('20', '!uptime', 'uptime');
INSERT INTO "permissions" VALUES ('21', '!warn', 'warn');
INSERT INTO "permissions" VALUES ('22', '!me', 'me');
INSERT INTO "permissions" VALUES ('100', '!admincheck', 'Admincheck');
COMMIT;

-- ----------------------------
--  Table structure for "rotate_message"
-- ----------------------------
DROP TABLE IF EXISTS "rotate_message";
CREATE TABLE "rotate_message" (
	 "id" integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	 "message" text NOT NULL
);

-- ----------------------------
--  Table structure for "rules_message"
-- ----------------------------
DROP TABLE IF EXISTS "rules_message";
CREATE TABLE "rules_message" (
	 "id" integer NOT NULL,
	 "rule_message" text NOT NULL,
	PRIMARY KEY("id")
);

-- ----------------------------
--  Table structure for "user"
-- ----------------------------
DROP TABLE IF EXISTS "user";
CREATE TABLE "user" (
	 "id" integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	 "playerid" integer NOT NULL,
	 "crdate" integer NOT NULL,
	 "nickname" text NOT NULL,
	 "ip" text,
	 "first_join" integer NOT NULL,
	 "last_seen" integer
);

-- ----------------------------
--  Table structure for "user_groups"
-- ----------------------------
DROP TABLE IF EXISTS "user_groups";
CREATE TABLE "user_groups" (
	 "id" integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	 "group_id" integer NOT NULL,
	 "user_id" integer NOT NULL
);

-- ----------------------------
--  Table structure for "user_stats"
-- ----------------------------
DROP TABLE IF EXISTS "user_stats";
CREATE TABLE "user_stats" (
	 "id" integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	 "playerid" integer NOT NULL,
	 "kick_count" integer DEFAULT '0',
	 "ban_count" integer DEFAULT '0',
	 "tempban_count" integer DEFAULT '0',
	 "kill_count" integer DEFAULT '0',
	 "death_count" integer DEFAULT '0',
	 "teamkill_count" integer
);

-- ----------------------------
--  Table structure for "user_stats_weapon"
-- ----------------------------
DROP TABLE IF EXISTS "user_stats_weapon";
CREATE TABLE "user_stats_weapon" (
	 "id" integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	 "killed_player" integer NOT NULL,
	 "weapon_id" integer NOT NULL,
	 "hitbox" integer NOT NULL,
	 "team" integer NOT NULL,
	 "enemy_team" integer NOT NULL,
	 "damage" integer NOT NULL
);

-- ----------------------------
--  Table structure for "word_filter"
-- ----------------------------
DROP TABLE IF EXISTS "word_filter";
CREATE TABLE "word_filter" (
	 "id" integer NOT NULL,
	 "phrase" text NOT NULL,
	 "exact" integer NOT NULL,
	PRIMARY KEY("id")
);

