enum script_actions {
	ACT_PRE_STREAM,
	ACT_PRE_DUMP,
	ACT_POST_DUMP,
	ACT_PRE_RESTORE,
	ACT_POST_RESTORE,
	ACT_NET_LOCK,
	ACT_NET_UNLOCK,
	ACT_SETUP_NS,
	ACT_POST_SETUP_NS,
	ACT_POST_RESUME,
	ACT_PRE_RESUME,
	ACT_ORPHAN_PTS_MASTER,
	ACT_STATUS_READY,
	ACT_QUERY_EXT_FILES,

	ACT_MAX
};