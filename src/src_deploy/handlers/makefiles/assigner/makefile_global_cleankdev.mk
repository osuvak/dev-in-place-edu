# /*
#  * This file is part of the "dev-in-place" repository located at:
#  * https://github.com/osuvak/dev-in-place
#  * 
#  * Copyright (C) 2017-2018  Onder Suvak
#  * 
#  * For licensing information check the above url.
#  * Please do not remove this header.
#  * */

# cleankdev : force_look
# 	@rm -rf ~/.kde4/share/apps/kdevelop
# 	@rm -rf ~/.cache/kdevduchain
# 	@cd ~/.kde4/share/apps; find . -wholename "./kdev*" -type d -exec rm -rf "{}" \;
# 	@set -o pipefail -e; \
# 	for d in $(DIRS); do cd $$d && $(MAKE) cleankdev && cd ..; done
	
cleankdev : force_look
	@dir_temp_kdev=~/.kde4/share/apps/kdevelop && \
	mkdir -p $${dir_temp_kdev} && rm -rf $${dir_temp_kdev}
	@dir_temp_kdev=~/.cache/kdevduchain && \
	mkdir -p $${dir_temp_kdev} && rm -rf $${dir_temp_kdev}
	@dir_temp_kdev=~/.kde4/share/apps && \
	mkdir -p $${dir_temp_kdev} && cd $${dir_temp_kdev} && \
	find . -wholename "./kdev*" -type d -print0 | xargs -0 rm -rf --
	@set -o pipefail -e; \
	for d in $(DIRS); do cd $$d && $(MAKE) cleankdev && cd ..; done