# pragma once
# include <dsn/service_api_cpp.h>

//
// uncomment the following line if you want to use 
// data encoding/decoding from the original tool instead of rDSN
// in this case, you need to use these tools to generate
// type files with --gen=cpp etc. options
//

# if defined(DSN_USE_THRIFT_SERIALIZATION)

# include "cli_types.h"

# elif defined(DSN_USE_PROTO_SERIALIZATION)

# include "cli.pb.h"

# else // use rDSN's data encoding/decoding

namespace dsn { 
    // ---------- command -------------
    struct command
    {
        std::string cmd;
        std::vector< std::string> arguments;
    };

    inline void marshall(::dsn::binary_writer& writer, const command& val)
    {
        marshall(writer, val.cmd);
        marshall(writer, val.arguments);
    }

    inline void unmarshall(::dsn::binary_reader& reader, /*out*/ command& val)
    {
        unmarshall(reader, val.cmd);
        unmarshall(reader, val.arguments);
    }

} 

#endif 
