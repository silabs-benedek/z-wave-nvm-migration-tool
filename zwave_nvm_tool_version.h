#ifndef ZWAVE_NVM_TOOL_VERSION_H
#define ZWAVE_NVM_TOOL_VERSION_H

/** X.x.x: Major version of the driver */
#define ZWAVE_NVM_TOOL_VERSION_MAJOR      1
/** x.X.x: Minor version of the driver */
#define ZWAVE_NVM_TOOL_VERSION_MINOR      0
/** x.x.X: Revision of the driver */
#define ZWAVE_NVM_TOOL_VERSION_REVISION   0
/* Some helper defines to get a version string */
#define ZWAVE_NVM_TOOL_VERSTR2(x) #x
#define ZWAVE_NVM_TOOL_VERSTR(x) ZWAVE_NVM_TOOL_VERSTR2(x)

/** Provides the version of the driver */
#define ZWAVE_NVM_TOOL_VERSION   ((ZWAVE_NVM_TOOL_VERSION_MAJOR) << 24   | (ZWAVE_NVM_TOOL_VERSION_MINOR) << 16 \
                               | (ZWAVE_NVM_TOOL_VERSION_REVISION) << 8
/** Provides the version of the driver as string */
#define ZWAVE_NVM_TOOL_VERSION_STRING     ZWAVE_NVM_TOOL_VERSTR(ZWAVE_NVM_TOOL_VERSION_MAJOR) "." \
  ZWAVE_NVM_TOOL_VERSTR(ZWAVE_NVM_TOOL_VERSION_MINOR) "."                                      \
  ZWAVE_NVM_TOOL_VERSTR(ZWAVE_NVM_TOOL_VERSION_REVISION)                                       \

#endif // ZWAVE_NVM_TOOL_VERSION_H