COMPONENT_NAME=memfault_coredump_utils

SRC_FILES = \
  $(MFLT_COMPONENTS_DIR)/panics/src/memfault_coredump_utils.c

MOCK_AND_FAKE_SRC_FILES += \
  $(MFLT_TEST_FAKE_DIR)/fake_memfault_platform_debug_log.c

TEST_SRC_FILES = \
  $(MFLT_TEST_SRC_DIR)/test_memfault_coredump_utils.cpp \
  $(MOCK_AND_FAKE_SRC_FILES)

include $(CPPUTEST_MAKFILE_INFRA)