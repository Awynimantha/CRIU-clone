#include "action-scripts.h"
#include "common/list.h"
#include "xmalloc.h"
#include "log.h"
#include "servicefd.h"

static const char *action_names[ACT_MAX] = {
	[ACT_PRE_STREAM] = "pre-stream",
	[ACT_PRE_DUMP] = "pre-dump",
	[ACT_POST_DUMP] = "post-dump",
	[ACT_PRE_RESTORE] = "pre-restore",
	[ACT_POST_RESTORE] = "post-restore",
	[ACT_NET_LOCK] = "network-lock",
	[ACT_NET_UNLOCK] = "network-unlock",
	[ACT_SETUP_NS] = "setup-namespaces",
	[ACT_POST_SETUP_NS] = "post-setup-namespaces",
	[ACT_PRE_RESUME] = "pre-resume",
	[ACT_POST_RESUME] = "post-resume",
	[ACT_ORPHAN_PTS_MASTER] = "orphan-pts-master",
	[ACT_STATUS_READY] = "status-ready",
	[ACT_QUERY_EXT_FILES] = "query-ext-files",
};

struct script {
    struct list_head node;
    char *path;
};

enum {SCRIPT_NONE, SCRIPTS_SHELL, SCRIPT_RPC};

static int scripts_mode = SCRIPT_NONE;
static LIST_HEAD(scripts);

static int run_shell_scripts(const char *action ) {
    int retval = 0;
    struct script *script;
    static unsigned env_set = 0;
	#define ENV_IMGDIR 0x1
	#define ENV_ROOTPID 0x2

	if(list_empty(&scripts))
		return 0;
	if(!(env_set & ENV_IMGDIR)) {
		char image_dir[PATH_MAX];
		sprintf(image_dir, "/proc/%ld/fd/%d", (long)getpid(), get_service_fd(IMG_FD_OFF));
		if (setenv("CRTOOLS_IMAGE_DIR", image_dir, 1)) {
			pr_perror("Can't set CRTOOLS_IMAGE_DIR=");	
		};\
	}
}