/* Copyright 2016 Tieu-Philippe KHIM (khim.tieu.philippe@gmail.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
 #include <libipset/data.h>			/* IPSET_OPT_* */
 #include <libipset/parse.h>			/* parser functions */
 #include <libipset/print.h>			/* printing functions */
 #include <libipset/types.h>			/* prototypes */

static const struct ipset_arg bitmap_macip_create_args0[] = {
  { .name = { "range", NULL },
    .has_arg = IPSET_MANDATORY_ARG,	.opt = IPSET_OPT_IP,
    .parse = ipset_parse_netrange,	.print = ipset_print_ip,
  },
  { .name = { "timeout", NULL },
    .has_arg = IPSET_MANDATORY_ARG, .opt = IPSET_OPT_TIMEOUT,
    .parse = ipset_parse_timeout,   .print = ipset_print_number,
  },
	{ .name = { "network", NULL },
	  .has_arg = IPSET_MANDATORY_ARG,	.opt = IPSET_OPT_IP,
	  .parse = ipset_parse_net,
	},
  { },
}

static const struct ipset_arg bitmap_macip_add_args0[] {
  {
    .name = { "timeout", NULL },
    .has_arg = IPSET_MANDATORY_ARG, .opt = IPSET_OPT_TIMEOUT,
    .parse = ipset_parse_timeout,   .print = ipset_print_number,
  },
  { },
}

static const char bitmap_macip_usage0[] =
"create SETNAME bitmap:mac,ipc range IP/CIDR|FROM-TO\n"
"               [matchunset] [timeout VALUE]\n"
"add    SETNAME MAC[,IP] [timeout VALUE]\n"
"del    SETNAME MAC[,IP]\n"
"test   SETNAME MAC[,IP]\n\n"
"where IP, FROM and TO are IPv4 addresses (or hostnames),\n"
"      CIDR is a valid IPv4 CIDR prefix,\n"
"      MAC is a valid MAC address.\n";
