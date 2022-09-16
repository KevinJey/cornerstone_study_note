/*
 * Copyright (c) 2016 - present Alpha Infra Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _DELAYED_TASK_SCHEDULER_HXX_
#define _DELAYED_TASK_SCHEDULER_HXX_

#include "basic_types.hxx"
#include "delayed_task.hxx"
#include "pp_util.hxx"
#include "ptr.hxx"

namespace cornerstone
{
class delayed_task_scheduler
{
    __interface_body__(delayed_task_scheduler);

public:
    virtual void schedule(ptr<delayed_task>& task, int32 milliseconds) = 0;

    void cancel(ptr<delayed_task>& task)
    {
        cancel_impl(task);
        task->cancel();
    }

private:
    virtual void cancel_impl(ptr<delayed_task>& task) = 0;
};
} // namespace cornerstone

#endif //_DELAYED_TASK_SCHEDULER_HXX_
