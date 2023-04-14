/*
 * This source file is part of an OSTIS project. For the latest info, see http://ostis.net
 * Distributed under the MIT License
 * (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
 */

#include "sc_memory_params.h"

void sc_memory_params_clear(sc_memory_params * params)
{
  params->version = (sc_char const *)null_ptr;
  params->clear = SC_FALSE;
  params->repo_path = (sc_char const *)null_ptr;
  params->ext_path = (sc_char const *)null_ptr;
  params->enabled_exts = (sc_char const **)null_ptr;
  params->save_period = DEFAULT_SAVE_PERIOD;      // seconds
  params->update_period = DEFAULT_UPDATE_PERIOD;  // seconds

  params->log_type = DEFAULT_LOG_TYPE;
  params->log_file = DEFAULT_LOG_FILE;
  params->log_level = DEFAULT_LOG_LEVEL;

  params->max_loaded_segments = DEFAULT_MAX_LOADED_SEGMENTS;
  params->max_threads = DEFAULT_MAX_THREADS;
  params->max_events_and_agents_threads = DEFAULT_EVENTS_PROCESSORS;

  params->init_memory_generated_structure = (sc_char const *)null_ptr;
  params->init_memory_generated_upload = SC_FALSE;
}
