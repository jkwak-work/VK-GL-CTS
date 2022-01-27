/* WARNING: This is auto-generated file. Do not modify, since changes will
 * be lost! Modify the generating script instead.
 */

PFN_vkVoidFunction DeviceDriverSC::getDeviceProcAddr (VkDevice device, const char* pName) const
{
		return m_vk.getDeviceProcAddr(device, pName);
}

void DeviceDriverSC::destroyDevice (VkDevice device, const VkAllocationCallbacks* pAllocator) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.destroyDevice(device, pAllocator);
	else
		destroyDeviceHandler(device, pAllocator);
}

void DeviceDriverSC::getDeviceQueue (VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.getDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
	else
		m_vk.getDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
}

VkResult DeviceDriverSC::queueSubmit (VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) const
{
	if (m_normalMode)
		return m_vk.queueSubmit(queue, submitCount, pSubmits, fence);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::queueWaitIdle (VkQueue queue) const
{
	if (m_normalMode)
		return m_vk.queueWaitIdle(queue);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::deviceWaitIdle (VkDevice device) const
{
	if (m_normalMode)
		return m_vk.deviceWaitIdle(device);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::allocateMemory (VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return m_vk.allocateMemory(device, pAllocateInfo, pAllocator, pMemory);
	else
	{
		DDSTAT_LOCK();
		DDSTAT_HANDLE_CREATE(deviceMemoryRequestCount,1);
		*pMemory = Handle<HANDLE_TYPE_DEVICE_MEMORY>(m_resourceInterface->incResourceCounter());
	}
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::mapMemory (VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return m_vk.mapMemory(device, memory, offset, size, flags, ppData);
	else
	{
		DDSTAT_LOCK();
		if(m_falseMemory.size() < (static_cast<std::size_t>(offset+size)))
			m_falseMemory.resize(static_cast<std::size_t>(offset+size));
		*ppData = (void*)m_falseMemory.data();
	}
	return VK_SUCCESS;
}

void DeviceDriverSC::unmapMemory (VkDevice device, VkDeviceMemory memory) const
{
	if (m_normalMode)
		m_vk.unmapMemory(device, memory);
}

VkResult DeviceDriverSC::flushMappedMemoryRanges (VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) const
{
	if (m_normalMode)
		return m_vk.flushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::invalidateMappedMemoryRanges (VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) const
{
	if (m_normalMode)
		return m_vk.invalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
	return VK_SUCCESS;
}

void DeviceDriverSC::getDeviceMemoryCommitment (VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes) const
{
	if (m_normalMode)
		m_vk.getDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
}

VkResult DeviceDriverSC::bindBufferMemory (VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset) const
{
	if (m_normalMode)
		return m_vk.bindBufferMemory(device, buffer, memory, memoryOffset);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::bindImageMemory (VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset) const
{
	if (m_normalMode)
		return m_vk.bindImageMemory(device, image, memory, memoryOffset);
	return VK_SUCCESS;
}

void DeviceDriverSC::getBufferMemoryRequirements (VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.getBufferMemoryRequirements(device, buffer, pMemoryRequirements);
	else
	{
		DDSTAT_LOCK();
		pMemoryRequirements->size = 1048576U;
		pMemoryRequirements->alignment = 1U;
		pMemoryRequirements->memoryTypeBits = ~0U;
	}
}

void DeviceDriverSC::getImageMemoryRequirements (VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.getImageMemoryRequirements(device, image, pMemoryRequirements);
	else
	{
		DDSTAT_LOCK();
		pMemoryRequirements->size = 1048576U;
		pMemoryRequirements->alignment = 1U;
		pMemoryRequirements->memoryTypeBits = ~0U;
	}
}

VkResult DeviceDriverSC::createFence (VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return m_vk.createFence(device, pCreateInfo, pAllocator, pFence);
	else
	{
		DDSTAT_LOCK();
		DDSTAT_HANDLE_CREATE(fenceRequestCount,1);
		*pFence = Handle<HANDLE_TYPE_FENCE>(m_resourceInterface->incResourceCounter());
	}
	return VK_SUCCESS;
}

void DeviceDriverSC::destroyFence (VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.destroyFence(device, fence, pAllocator);
	else
	{
		DDSTAT_LOCK();
		DDSTAT_HANDLE_DESTROY_IF(fence,fenceRequestCount,1);
	}
}

VkResult DeviceDriverSC::resetFences (VkDevice device, uint32_t fenceCount, const VkFence* pFences) const
{
	if (m_normalMode)
		return m_vk.resetFences(device, fenceCount, pFences);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::getFenceStatus (VkDevice device, VkFence fence) const
{
	if (m_normalMode)
		return m_vk.getFenceStatus(device, fence);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::waitForFences (VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout) const
{
	if (m_normalMode)
		return m_vk.waitForFences(device, fenceCount, pFences, waitAll, timeout);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::createSemaphore (VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return m_vk.createSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
	else
	{
		DDSTAT_LOCK();
		DDSTAT_HANDLE_CREATE(semaphoreRequestCount,1);
		*pSemaphore = Handle<HANDLE_TYPE_SEMAPHORE>(m_resourceInterface->incResourceCounter());
	}
	return VK_SUCCESS;
}

void DeviceDriverSC::destroySemaphore (VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.destroySemaphore(device, semaphore, pAllocator);
	else
	{
		DDSTAT_LOCK();
		DDSTAT_HANDLE_DESTROY_IF(semaphore,semaphoreRequestCount,1);
	}
}

VkResult DeviceDriverSC::createEvent (VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return m_vk.createEvent(device, pCreateInfo, pAllocator, pEvent);
	else
	{
		DDSTAT_LOCK();
		DDSTAT_HANDLE_CREATE(eventRequestCount,1);
		*pEvent = Handle<HANDLE_TYPE_EVENT>(m_resourceInterface->incResourceCounter());
	}
	return VK_SUCCESS;
}

void DeviceDriverSC::destroyEvent (VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.destroyEvent(device, event, pAllocator);
	else
	{
		DDSTAT_LOCK();
		DDSTAT_HANDLE_DESTROY_IF(event,eventRequestCount,1);
	}
}

VkResult DeviceDriverSC::getEventStatus (VkDevice device, VkEvent event) const
{
	if (m_normalMode)
		return m_vk.getEventStatus(device, event);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::setEvent (VkDevice device, VkEvent event) const
{
	if (m_normalMode)
		return m_vk.setEvent(device, event);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::resetEvent (VkDevice device, VkEvent event) const
{
	if (m_normalMode)
		return m_vk.resetEvent(device, event);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::createQueryPool (VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return m_vk.createQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
	else
		createQueryPoolHandler(device, pCreateInfo, pAllocator, pQueryPool);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::getQueryPoolResults (VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags) const
{
	if (m_normalMode)
		return m_vk.getQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::createBuffer (VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return m_vk.createBuffer(device, pCreateInfo, pAllocator, pBuffer);
	else
	{
		DDSTAT_LOCK();
		DDSTAT_HANDLE_CREATE(bufferRequestCount,1);
		*pBuffer = Handle<HANDLE_TYPE_BUFFER>(m_resourceInterface->incResourceCounter());
	}
	return VK_SUCCESS;
}

void DeviceDriverSC::destroyBuffer (VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.destroyBuffer(device, buffer, pAllocator);
	else
	{
		DDSTAT_LOCK();
		DDSTAT_HANDLE_DESTROY_IF(buffer,bufferRequestCount,1);
	}
}

VkResult DeviceDriverSC::createBufferView (VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return m_vk.createBufferView(device, pCreateInfo, pAllocator, pView);
	else
	{
		DDSTAT_LOCK();
		DDSTAT_HANDLE_CREATE(bufferViewRequestCount,1);
		*pView = Handle<HANDLE_TYPE_BUFFER_VIEW>(m_resourceInterface->incResourceCounter());
	}
	return VK_SUCCESS;
}

void DeviceDriverSC::destroyBufferView (VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.destroyBufferView(device, bufferView, pAllocator);
	else
	{
		DDSTAT_LOCK();
		DDSTAT_HANDLE_DESTROY_IF(bufferView,bufferViewRequestCount,1);
	}
}

VkResult DeviceDriverSC::createImage (VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return m_vk.createImage(device, pCreateInfo, pAllocator, pImage);
	else
	{
		DDSTAT_LOCK();
		DDSTAT_HANDLE_CREATE(imageRequestCount,1);
		*pImage = Handle<HANDLE_TYPE_IMAGE>(m_resourceInterface->incResourceCounter());
	}
	return VK_SUCCESS;
}

void DeviceDriverSC::destroyImage (VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.destroyImage(device, image, pAllocator);
	else
	{
		DDSTAT_LOCK();
		DDSTAT_HANDLE_DESTROY_IF(image,imageRequestCount,1);
	}
}

void DeviceDriverSC::getImageSubresourceLayout (VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.getImageSubresourceLayout(device, image, pSubresource, pLayout);
	else
	{
		DDSTAT_LOCK();
		pLayout->offset = 0U;
		pLayout->size = 1048576U;
		pLayout->rowPitch = 0U;
		pLayout->arrayPitch = 0U;
		pLayout->depthPitch = 0U;
	}
}

VkResult DeviceDriverSC::createImageView (VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return m_vk.createImageView(device, pCreateInfo, pAllocator, pView);
	else
		createImageViewHandler(device, pCreateInfo, pAllocator, pView);
	return VK_SUCCESS;
}

void DeviceDriverSC::destroyImageView (VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.destroyImageView(device, imageView, pAllocator);
	else
		destroyImageViewHandler(device, imageView, pAllocator);
}

VkResult DeviceDriverSC::createPipelineCache (VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return m_vk.createPipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);
	else
	{
		DDSTAT_LOCK();
		DDSTAT_HANDLE_CREATE(pipelineCacheRequestCount,1);
		*pPipelineCache = Handle<HANDLE_TYPE_PIPELINE_CACHE>(m_resourceInterface->incResourceCounter());
	}
	return VK_SUCCESS;
}

void DeviceDriverSC::destroyPipelineCache (VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.destroyPipelineCache(device, pipelineCache, pAllocator);
	else
	{
		DDSTAT_LOCK();
		DDSTAT_HANDLE_DESTROY_IF(pipelineCache,pipelineCacheRequestCount,1);
	}
}

VkResult DeviceDriverSC::createGraphicsPipelines (VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return createGraphicsPipelinesHandlerNorm(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
	else
		createGraphicsPipelinesHandlerStat(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::createComputePipelines (VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return createComputePipelinesHandlerNorm(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
	else
		createComputePipelinesHandlerStat(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
	return VK_SUCCESS;
}

void DeviceDriverSC::destroyPipeline (VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.destroyPipeline(device, pipeline, pAllocator);
	else
		destroyPipelineHandler(device, pipeline, pAllocator);
}

VkResult DeviceDriverSC::createPipelineLayout (VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return createPipelineLayoutHandlerNorm(device, pCreateInfo, pAllocator, pPipelineLayout);
	else
		createPipelineLayoutHandlerStat(device, pCreateInfo, pAllocator, pPipelineLayout);
	return VK_SUCCESS;
}

void DeviceDriverSC::destroyPipelineLayout (VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.destroyPipelineLayout(device, pipelineLayout, pAllocator);
	else
	{
		DDSTAT_LOCK();
		DDSTAT_HANDLE_DESTROY_IF(pipelineLayout,pipelineLayoutRequestCount,1);
	}
}

VkResult DeviceDriverSC::createSampler (VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return createSamplerHandlerNorm(device, pCreateInfo, pAllocator, pSampler);
	else
		createSamplerHandlerStat(device, pCreateInfo, pAllocator, pSampler);
	return VK_SUCCESS;
}

void DeviceDriverSC::destroySampler (VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.destroySampler(device, sampler, pAllocator);
	else
	{
		DDSTAT_LOCK();
		DDSTAT_HANDLE_DESTROY_IF(sampler,samplerRequestCount,1);
	}
}

VkResult DeviceDriverSC::createDescriptorSetLayout (VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return createDescriptorSetLayoutHandlerNorm(device, pCreateInfo, pAllocator, pSetLayout);
	else
		createDescriptorSetLayoutHandlerStat(device, pCreateInfo, pAllocator, pSetLayout);
	return VK_SUCCESS;
}

void DeviceDriverSC::destroyDescriptorSetLayout (VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.destroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
	else
		destroyDescriptorSetLayoutHandler(device, descriptorSetLayout, pAllocator);
}

VkResult DeviceDriverSC::createDescriptorPool (VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return m_vk.createDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
	else
	{
		DDSTAT_LOCK();
		DDSTAT_HANDLE_CREATE(descriptorPoolRequestCount,1);
		*pDescriptorPool = Handle<HANDLE_TYPE_DESCRIPTOR_POOL>(m_resourceInterface->incResourceCounter());
	}
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::resetDescriptorPool (VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return m_vk.resetDescriptorPool(device, descriptorPool, flags);
	else
		resetDescriptorPoolHandlerStat(device, descriptorPool, flags);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::allocateDescriptorSets (VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return m_vk.allocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);
	else
		allocateDescriptorSetsHandlerStat(device, pAllocateInfo, pDescriptorSets);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::freeDescriptorSets (VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return m_vk.freeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
	else
		freeDescriptorSetsHandlerStat(device, descriptorPool, descriptorSetCount, pDescriptorSets);
	return VK_SUCCESS;
}

void DeviceDriverSC::updateDescriptorSets (VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies) const
{
	if (m_normalMode)
		m_vk.updateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
}

VkResult DeviceDriverSC::createFramebuffer (VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return createFramebufferHandlerNorm(device, pCreateInfo, pAllocator, pFramebuffer);
	else
		createFramebufferHandlerStat(device, pCreateInfo, pAllocator, pFramebuffer);
	return VK_SUCCESS;
}

void DeviceDriverSC::destroyFramebuffer (VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.destroyFramebuffer(device, framebuffer, pAllocator);
	else
	{
		DDSTAT_LOCK();
		DDSTAT_HANDLE_DESTROY_IF(framebuffer,framebufferRequestCount,1);
	}
}

VkResult DeviceDriverSC::createRenderPass (VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return createRenderPassHandlerNorm(device, pCreateInfo, pAllocator, pRenderPass);
	else
		createRenderPassHandlerStat(device, pCreateInfo, pAllocator, pRenderPass);
	return VK_SUCCESS;
}

void DeviceDriverSC::destroyRenderPass (VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.destroyRenderPass(device, renderPass, pAllocator);
	else
		destroyRenderPassHandler(device, renderPass, pAllocator);
}

void DeviceDriverSC::getRenderAreaGranularity (VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity) const
{
	if (m_normalMode)
		m_vk.getRenderAreaGranularity(device, renderPass, pGranularity);
}

VkResult DeviceDriverSC::createCommandPool (VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return createCommandPoolHandlerNorm(device, pCreateInfo, pAllocator, pCommandPool);
	else
		createCommandPoolHandlerStat(device, pCreateInfo, pAllocator, pCommandPool);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::resetCommandPool (VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return resetCommandPoolHandlerNorm(device, commandPool, flags);
	else
		resetCommandPoolHandlerStat(device, commandPool, flags);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::allocateCommandBuffers (VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return m_vk.allocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
	else
		allocateCommandBuffersHandler(device, pAllocateInfo, pCommandBuffers);
	return VK_SUCCESS;
}

void DeviceDriverSC::freeCommandBuffers (VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.freeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
	else
		freeCommandBuffersHandler(device, commandPool, commandBufferCount, pCommandBuffers);
}

VkResult DeviceDriverSC::beginCommandBuffer (VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo) const
{
	if (m_normalMode)
		return m_vk.beginCommandBuffer(commandBuffer, pBeginInfo);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::endCommandBuffer (VkCommandBuffer commandBuffer) const
{
	if (m_normalMode)
		return m_vk.endCommandBuffer(commandBuffer);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::resetCommandBuffer (VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) const
{
	if (m_normalMode)
		return m_vk.resetCommandBuffer(commandBuffer, flags);
	return VK_SUCCESS;
}

void DeviceDriverSC::cmdBindPipeline (VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) const
{
	if (m_normalMode)
		m_vk.cmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetViewport (VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports) const
{
	if (m_normalMode)
		m_vk.cmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetScissor (VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors) const
{
	if (m_normalMode)
		m_vk.cmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetLineWidth (VkCommandBuffer commandBuffer, float lineWidth) const
{
	if (m_normalMode)
		m_vk.cmdSetLineWidth(commandBuffer, lineWidth);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetDepthBias (VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) const
{
	if (m_normalMode)
		m_vk.cmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetBlendConstants (VkCommandBuffer commandBuffer, const float blendConstants[4]) const
{
	if (m_normalMode)
		m_vk.cmdSetBlendConstants(commandBuffer, blendConstants);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetDepthBounds (VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) const
{
	if (m_normalMode)
		m_vk.cmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetStencilCompareMask (VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask) const
{
	if (m_normalMode)
		m_vk.cmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetStencilWriteMask (VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) const
{
	if (m_normalMode)
		m_vk.cmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetStencilReference (VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) const
{
	if (m_normalMode)
		m_vk.cmdSetStencilReference(commandBuffer, faceMask, reference);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdBindDescriptorSets (VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets) const
{
	if (m_normalMode)
		m_vk.cmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdBindIndexBuffer (VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType) const
{
	if (m_normalMode)
		m_vk.cmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdBindVertexBuffers (VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) const
{
	if (m_normalMode)
		m_vk.cmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdDraw (VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) const
{
	if (m_normalMode)
		m_vk.cmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdDrawIndexed (VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) const
{
	if (m_normalMode)
		m_vk.cmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdDrawIndirect (VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) const
{
	if (m_normalMode)
		m_vk.cmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdDrawIndexedIndirect (VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) const
{
	if (m_normalMode)
		m_vk.cmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdDispatch (VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) const
{
	if (m_normalMode)
		m_vk.cmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdDispatchIndirect (VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) const
{
	if (m_normalMode)
		m_vk.cmdDispatchIndirect(commandBuffer, buffer, offset);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdCopyBuffer (VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions) const
{
	if (m_normalMode)
		m_vk.cmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdCopyImage (VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions) const
{
	if (m_normalMode)
		m_vk.cmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdBlitImage (VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter) const
{
	if (m_normalMode)
		m_vk.cmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdCopyBufferToImage (VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions) const
{
	if (m_normalMode)
		m_vk.cmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdCopyImageToBuffer (VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) const
{
	if (m_normalMode)
		m_vk.cmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdUpdateBuffer (VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.cmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
	else
		increaseCommandBufferSize(commandBuffer, dataSize);
}

void DeviceDriverSC::cmdFillBuffer (VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data) const
{
	if (m_normalMode)
		m_vk.cmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdClearColorImage (VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) const
{
	if (m_normalMode)
		m_vk.cmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdClearDepthStencilImage (VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) const
{
	if (m_normalMode)
		m_vk.cmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdClearAttachments (VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects) const
{
	if (m_normalMode)
		m_vk.cmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdResolveImage (VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions) const
{
	if (m_normalMode)
		m_vk.cmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetEvent (VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) const
{
	if (m_normalMode)
		m_vk.cmdSetEvent(commandBuffer, event, stageMask);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdResetEvent (VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) const
{
	if (m_normalMode)
		m_vk.cmdResetEvent(commandBuffer, event, stageMask);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdWaitEvents (VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) const
{
	if (m_normalMode)
		m_vk.cmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdPipelineBarrier (VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) const
{
	if (m_normalMode)
		m_vk.cmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdBeginQuery (VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags) const
{
	if (m_normalMode)
		m_vk.cmdBeginQuery(commandBuffer, queryPool, query, flags);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdEndQuery (VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) const
{
	if (m_normalMode)
		m_vk.cmdEndQuery(commandBuffer, queryPool, query);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdResetQueryPool (VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) const
{
	if (m_normalMode)
		m_vk.cmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdWriteTimestamp (VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query) const
{
	if (m_normalMode)
		m_vk.cmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdCopyQueryPoolResults (VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) const
{
	if (m_normalMode)
		m_vk.cmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdPushConstants (VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues) const
{
	if (m_normalMode)
		m_vk.cmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdBeginRenderPass (VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents) const
{
	if (m_normalMode)
		m_vk.cmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdNextSubpass (VkCommandBuffer commandBuffer, VkSubpassContents contents) const
{
	if (m_normalMode)
		m_vk.cmdNextSubpass(commandBuffer, contents);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdEndRenderPass (VkCommandBuffer commandBuffer) const
{
	if (m_normalMode)
		m_vk.cmdEndRenderPass(commandBuffer);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdExecuteCommands (VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) const
{
	if (m_normalMode)
		m_vk.cmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

VkResult DeviceDriverSC::bindBufferMemory2 (VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) const
{
	if (m_normalMode)
		return m_vk.bindBufferMemory2(device, bindInfoCount, pBindInfos);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::bindImageMemory2 (VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) const
{
	if (m_normalMode)
		return m_vk.bindImageMemory2(device, bindInfoCount, pBindInfos);
	return VK_SUCCESS;
}

void DeviceDriverSC::getDeviceGroupPeerMemoryFeatures (VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) const
{
	if (m_normalMode)
		m_vk.getDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}

void DeviceDriverSC::cmdSetDeviceMask (VkCommandBuffer commandBuffer, uint32_t deviceMask) const
{
	if (m_normalMode)
		m_vk.cmdSetDeviceMask(commandBuffer, deviceMask);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdDispatchBase (VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) const
{
	if (m_normalMode)
		m_vk.cmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::getImageMemoryRequirements2 (VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.getImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
	else
	{
		DDSTAT_LOCK();
		pMemoryRequirements->memoryRequirements.size = 1048576U;
		pMemoryRequirements->memoryRequirements.alignment = 1U;
		pMemoryRequirements->memoryRequirements.memoryTypeBits = ~0U;
	}
}

void DeviceDriverSC::getBufferMemoryRequirements2 (VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.getBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
	else
	{
		DDSTAT_LOCK();
		pMemoryRequirements->memoryRequirements.size = 1048576U;
		pMemoryRequirements->memoryRequirements.alignment = 1U;
		pMemoryRequirements->memoryRequirements.memoryTypeBits = ~0U;
	}
}

void DeviceDriverSC::getDeviceQueue2 (VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) const
{
	if (m_normalMode)
		m_vk.getDeviceQueue2(device, pQueueInfo, pQueue);
}

VkResult DeviceDriverSC::createSamplerYcbcrConversion (VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return createSamplerYcbcrConversionHandlerNorm(device, pCreateInfo, pAllocator, pYcbcrConversion);
	else
		createSamplerYcbcrConversionHandlerStat(device, pCreateInfo, pAllocator, pYcbcrConversion);
	return VK_SUCCESS;
}

void DeviceDriverSC::destroySamplerYcbcrConversion (VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.destroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);
	else
	{
		DDSTAT_LOCK();
		DDSTAT_HANDLE_DESTROY_IF(ycbcrConversion,samplerYcbcrConversionRequestCount,1);
	}
}

void DeviceDriverSC::getDescriptorSetLayoutSupport (VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		m_vk.getDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);
	else
		getDescriptorSetLayoutSupportHandler(device, pCreateInfo, pSupport);
}

void DeviceDriverSC::cmdDrawIndirectCount (VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) const
{
	if (m_normalMode)
		m_vk.cmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdDrawIndexedIndirectCount (VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) const
{
	if (m_normalMode)
		m_vk.cmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

VkResult DeviceDriverSC::createRenderPass2 (VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) const
{
	std::lock_guard<std::mutex> lock(functionMutex);
	if (m_normalMode)
		return createRenderPass2HandlerNorm(device, pCreateInfo, pAllocator, pRenderPass);
	else
		createRenderPass2HandlerStat(device, pCreateInfo, pAllocator, pRenderPass);
	return VK_SUCCESS;
}

void DeviceDriverSC::cmdBeginRenderPass2 (VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo) const
{
	if (m_normalMode)
		m_vk.cmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdNextSubpass2 (VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo) const
{
	if (m_normalMode)
		m_vk.cmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdEndRenderPass2 (VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) const
{
	if (m_normalMode)
		m_vk.cmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::resetQueryPool (VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) const
{
	if (m_normalMode)
		m_vk.resetQueryPool(device, queryPool, firstQuery, queryCount);
}

VkResult DeviceDriverSC::getSemaphoreCounterValue (VkDevice device, VkSemaphore semaphore, uint64_t* pValue) const
{
	if (m_normalMode)
		return m_vk.getSemaphoreCounterValue(device, semaphore, pValue);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::waitSemaphores (VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) const
{
	if (m_normalMode)
		return m_vk.waitSemaphores(device, pWaitInfo, timeout);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::signalSemaphore (VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) const
{
	if (m_normalMode)
		return m_vk.signalSemaphore(device, pSignalInfo);
	return VK_SUCCESS;
}

VkDeviceAddress DeviceDriverSC::getBufferDeviceAddress (VkDevice device, const VkBufferDeviceAddressInfo* pInfo) const
{
	if (m_normalMode)
		return m_vk.getBufferDeviceAddress(device, pInfo);
	return 0u;
}

uint64_t DeviceDriverSC::getBufferOpaqueCaptureAddress (VkDevice device, const VkBufferDeviceAddressInfo* pInfo) const
{
	if (m_normalMode)
		return m_vk.getBufferOpaqueCaptureAddress(device, pInfo);
	return 0u;
}

uint64_t DeviceDriverSC::getDeviceMemoryOpaqueCaptureAddress (VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) const
{
	if (m_normalMode)
		return m_vk.getDeviceMemoryOpaqueCaptureAddress(device, pInfo);
	return 0u;
}

void DeviceDriverSC::getCommandPoolMemoryConsumption (VkDevice device, VkCommandPool commandPool, VkCommandBuffer commandBuffer, VkCommandPoolMemoryConsumption* pConsumption) const
{
	if (m_normalMode)
		m_vk.getCommandPoolMemoryConsumption(device, commandPool, commandBuffer, pConsumption);
}

VkResult DeviceDriverSC::getFaultData (VkDevice device, VkFaultQueryBehavior faultQueryBehavior, VkBool32* pUnrecordedFaults, uint32_t* pFaultCount, VkFaultData* pFaults) const
{
	if (m_normalMode)
		return m_vk.getFaultData(device, faultQueryBehavior, pUnrecordedFaults, pFaultCount, pFaults);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::createSwapchainKHR (VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain) const
{
	if (m_normalMode)
		return m_vk.createSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::getSwapchainImagesKHR (VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages) const
{
	if (m_normalMode)
		return m_vk.getSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::acquireNextImageKHR (VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) const
{
	if (m_normalMode)
		return m_vk.acquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::queuePresentKHR (VkQueue queue, const VkPresentInfoKHR* pPresentInfo) const
{
	if (m_normalMode)
		return m_vk.queuePresentKHR(queue, pPresentInfo);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::getDeviceGroupPresentCapabilitiesKHR (VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities) const
{
	if (m_normalMode)
		return m_vk.getDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::getDeviceGroupSurfacePresentModesKHR (VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes) const
{
	if (m_normalMode)
		return m_vk.getDeviceGroupSurfacePresentModesKHR(device, surface, pModes);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::acquireNextImage2KHR (VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex) const
{
	if (m_normalMode)
		return m_vk.acquireNextImage2KHR(device, pAcquireInfo, pImageIndex);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::createSharedSwapchainsKHR (VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains) const
{
	if (m_normalMode)
		return m_vk.createSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::getMemoryFdKHR (VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd) const
{
	if (m_normalMode)
		return m_vk.getMemoryFdKHR(device, pGetFdInfo, pFd);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::getMemoryFdPropertiesKHR (VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties) const
{
	if (m_normalMode)
		return m_vk.getMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::importSemaphoreFdKHR (VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo) const
{
	if (m_normalMode)
		return m_vk.importSemaphoreFdKHR(device, pImportSemaphoreFdInfo);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::getSemaphoreFdKHR (VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd) const
{
	if (m_normalMode)
		return m_vk.getSemaphoreFdKHR(device, pGetFdInfo, pFd);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::getSwapchainStatusKHR (VkDevice device, VkSwapchainKHR swapchain) const
{
	if (m_normalMode)
		return m_vk.getSwapchainStatusKHR(device, swapchain);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::importFenceFdKHR (VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo) const
{
	if (m_normalMode)
		return m_vk.importFenceFdKHR(device, pImportFenceFdInfo);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::getFenceFdKHR (VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd) const
{
	if (m_normalMode)
		return m_vk.getFenceFdKHR(device, pGetFdInfo, pFd);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::acquireProfilingLockKHR (VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo) const
{
	if (m_normalMode)
		return m_vk.acquireProfilingLockKHR(device, pInfo);
	return VK_SUCCESS;
}

void DeviceDriverSC::releaseProfilingLockKHR (VkDevice device) const
{
	if (m_normalMode)
		m_vk.releaseProfilingLockKHR(device);
}

void DeviceDriverSC::cmdSetFragmentShadingRateKHR (VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) const
{
	if (m_normalMode)
		m_vk.cmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdRefreshObjectsKHR (VkCommandBuffer commandBuffer, const VkRefreshObjectListKHR* pRefreshObjects) const
{
	if (m_normalMode)
		m_vk.cmdRefreshObjectsKHR(commandBuffer, pRefreshObjects);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetEvent2KHR (VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfoKHR* pDependencyInfo) const
{
	if (m_normalMode)
		m_vk.cmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdResetEvent2KHR (VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2KHR stageMask) const
{
	if (m_normalMode)
		m_vk.cmdResetEvent2KHR(commandBuffer, event, stageMask);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdWaitEvents2KHR (VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfoKHR* pDependencyInfos) const
{
	if (m_normalMode)
		m_vk.cmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdPipelineBarrier2KHR (VkCommandBuffer commandBuffer, const VkDependencyInfoKHR* pDependencyInfo) const
{
	if (m_normalMode)
		m_vk.cmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdWriteTimestamp2KHR (VkCommandBuffer commandBuffer, VkPipelineStageFlags2KHR stage, VkQueryPool queryPool, uint32_t query) const
{
	if (m_normalMode)
		m_vk.cmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

VkResult DeviceDriverSC::queueSubmit2KHR (VkQueue queue, uint32_t submitCount, const VkSubmitInfo2KHR* pSubmits, VkFence fence) const
{
	if (m_normalMode)
		return m_vk.queueSubmit2KHR(queue, submitCount, pSubmits, fence);
	return VK_SUCCESS;
}

void DeviceDriverSC::cmdWriteBufferMarker2AMD (VkCommandBuffer commandBuffer, VkPipelineStageFlags2KHR stage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) const
{
	if (m_normalMode)
		m_vk.cmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::getQueueCheckpointData2NV (VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointData2NV* pCheckpointData) const
{
	if (m_normalMode)
		m_vk.getQueueCheckpointData2NV(queue, pCheckpointDataCount, pCheckpointData);
}

void DeviceDriverSC::cmdCopyBuffer2KHR (VkCommandBuffer commandBuffer, const VkCopyBufferInfo2KHR* pCopyBufferInfo) const
{
	if (m_normalMode)
		m_vk.cmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdCopyImage2KHR (VkCommandBuffer commandBuffer, const VkCopyImageInfo2KHR* pCopyImageInfo) const
{
	if (m_normalMode)
		m_vk.cmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdCopyBufferToImage2KHR (VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2KHR* pCopyBufferToImageInfo) const
{
	if (m_normalMode)
		m_vk.cmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdCopyImageToBuffer2KHR (VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2KHR* pCopyImageToBufferInfo) const
{
	if (m_normalMode)
		m_vk.cmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdBlitImage2KHR (VkCommandBuffer commandBuffer, const VkBlitImageInfo2KHR* pBlitImageInfo) const
{
	if (m_normalMode)
		m_vk.cmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdResolveImage2KHR (VkCommandBuffer commandBuffer, const VkResolveImageInfo2KHR* pResolveImageInfo) const
{
	if (m_normalMode)
		m_vk.cmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

VkResult DeviceDriverSC::displayPowerControlEXT (VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo) const
{
	if (m_normalMode)
		return m_vk.displayPowerControlEXT(device, display, pDisplayPowerInfo);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::registerDeviceEventEXT (VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) const
{
	if (m_normalMode)
		return m_vk.registerDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::registerDisplayEventEXT (VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) const
{
	if (m_normalMode)
		return m_vk.registerDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::getSwapchainCounterEXT (VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue) const
{
	if (m_normalMode)
		return m_vk.getSwapchainCounterEXT(device, swapchain, counter, pCounterValue);
	return VK_SUCCESS;
}

void DeviceDriverSC::cmdSetDiscardRectangleEXT (VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) const
{
	if (m_normalMode)
		m_vk.cmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::setHdrMetadataEXT (VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata) const
{
	if (m_normalMode)
		m_vk.setHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);
}

VkResult DeviceDriverSC::setDebugUtilsObjectNameEXT (VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) const
{
	if (m_normalMode)
		return m_vk.setDebugUtilsObjectNameEXT(device, pNameInfo);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::setDebugUtilsObjectTagEXT (VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo) const
{
	if (m_normalMode)
		return m_vk.setDebugUtilsObjectTagEXT(device, pTagInfo);
	return VK_SUCCESS;
}

void DeviceDriverSC::queueBeginDebugUtilsLabelEXT (VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) const
{
	if (m_normalMode)
		m_vk.queueBeginDebugUtilsLabelEXT(queue, pLabelInfo);
}

void DeviceDriverSC::queueEndDebugUtilsLabelEXT (VkQueue queue) const
{
	if (m_normalMode)
		m_vk.queueEndDebugUtilsLabelEXT(queue);
}

void DeviceDriverSC::queueInsertDebugUtilsLabelEXT (VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) const
{
	if (m_normalMode)
		m_vk.queueInsertDebugUtilsLabelEXT(queue, pLabelInfo);
}

void DeviceDriverSC::cmdBeginDebugUtilsLabelEXT (VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) const
{
	if (m_normalMode)
		m_vk.cmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdEndDebugUtilsLabelEXT (VkCommandBuffer commandBuffer) const
{
	if (m_normalMode)
		m_vk.cmdEndDebugUtilsLabelEXT(commandBuffer);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdInsertDebugUtilsLabelEXT (VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) const
{
	if (m_normalMode)
		m_vk.cmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetSampleLocationsEXT (VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo) const
{
	if (m_normalMode)
		m_vk.cmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

VkResult DeviceDriverSC::getImageDrmFormatModifierPropertiesEXT (VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties) const
{
	if (m_normalMode)
		return m_vk.getImageDrmFormatModifierPropertiesEXT(device, image, pProperties);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::getMemoryHostPointerPropertiesEXT (VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties) const
{
	if (m_normalMode)
		return m_vk.getMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties);
	return VK_SUCCESS;
}

VkResult DeviceDriverSC::getCalibratedTimestampsEXT (VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoEXT* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) const
{
	if (m_normalMode)
		return m_vk.getCalibratedTimestampsEXT(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
	return VK_SUCCESS;
}

void DeviceDriverSC::cmdSetLineStippleEXT (VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) const
{
	if (m_normalMode)
		m_vk.cmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetCullModeEXT (VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) const
{
	if (m_normalMode)
		m_vk.cmdSetCullModeEXT(commandBuffer, cullMode);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetFrontFaceEXT (VkCommandBuffer commandBuffer, VkFrontFace frontFace) const
{
	if (m_normalMode)
		m_vk.cmdSetFrontFaceEXT(commandBuffer, frontFace);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetPrimitiveTopologyEXT (VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) const
{
	if (m_normalMode)
		m_vk.cmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetViewportWithCountEXT (VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) const
{
	if (m_normalMode)
		m_vk.cmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetScissorWithCountEXT (VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) const
{
	if (m_normalMode)
		m_vk.cmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdBindVertexBuffers2EXT (VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) const
{
	if (m_normalMode)
		m_vk.cmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetDepthTestEnableEXT (VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) const
{
	if (m_normalMode)
		m_vk.cmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetDepthWriteEnableEXT (VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) const
{
	if (m_normalMode)
		m_vk.cmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetDepthCompareOpEXT (VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) const
{
	if (m_normalMode)
		m_vk.cmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetDepthBoundsTestEnableEXT (VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) const
{
	if (m_normalMode)
		m_vk.cmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetStencilTestEnableEXT (VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) const
{
	if (m_normalMode)
		m_vk.cmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetStencilOpEXT (VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) const
{
	if (m_normalMode)
		m_vk.cmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetVertexInputEXT (VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) const
{
	if (m_normalMode)
		m_vk.cmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetPatchControlPointsEXT (VkCommandBuffer commandBuffer, uint32_t patchControlPoints) const
{
	if (m_normalMode)
		m_vk.cmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetRasterizerDiscardEnableEXT (VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) const
{
	if (m_normalMode)
		m_vk.cmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetDepthBiasEnableEXT (VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) const
{
	if (m_normalMode)
		m_vk.cmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetLogicOpEXT (VkCommandBuffer commandBuffer, VkLogicOp logicOp) const
{
	if (m_normalMode)
		m_vk.cmdSetLogicOpEXT(commandBuffer, logicOp);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetPrimitiveRestartEnableEXT (VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) const
{
	if (m_normalMode)
		m_vk.cmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}

void DeviceDriverSC::cmdSetColorWriteEnableEXT (VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkBool32* pColorWriteEnables) const
{
	if (m_normalMode)
		m_vk.cmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
	else
		increaseCommandBufferSize(commandBuffer, 0u);
}