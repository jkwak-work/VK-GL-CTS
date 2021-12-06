/* WARNING: This is auto-generated file. Do not modify, since changes will
 * be lost! Modify the generating script instead.
 */

void getInstanceExtensionFunctions (uint32_t apiVersion, ::std::string extName, ::std::vector<const char*>& functions)
{
	if (extName == "VK_KHR_surface")
	{
		functions.push_back("vkDestroySurfaceKHR");
		functions.push_back("vkGetPhysicalDeviceSurfaceSupportKHR");
		functions.push_back("vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
		functions.push_back("vkGetPhysicalDeviceSurfaceFormatsKHR");
		functions.push_back("vkGetPhysicalDeviceSurfacePresentModesKHR");
		return;
	}
	if (extName == "VK_KHR_swapchain")
	{
		if(apiVersion >= VK_API_VERSION_1_1) functions.push_back("vkGetPhysicalDevicePresentRectanglesKHR");
		return;
	}
	if (extName == "VK_KHR_display")
	{
		functions.push_back("vkGetPhysicalDeviceDisplayPropertiesKHR");
		functions.push_back("vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
		functions.push_back("vkGetDisplayPlaneSupportedDisplaysKHR");
		functions.push_back("vkGetDisplayModePropertiesKHR");
		functions.push_back("vkCreateDisplayModeKHR");
		functions.push_back("vkGetDisplayPlaneCapabilitiesKHR");
		functions.push_back("vkCreateDisplayPlaneSurfaceKHR");
		return;
	}
	if (extName == "VK_KHR_display_swapchain")
	{
		return;
	}
	if (extName == "VK_KHR_external_memory_fd")
	{
		return;
	}
	if (extName == "VK_KHR_external_semaphore_fd")
	{
		return;
	}
	if (extName == "VK_KHR_incremental_present")
	{
		return;
	}
	if (extName == "VK_KHR_shared_presentable_image")
	{
		return;
	}
	if (extName == "VK_KHR_external_fence_fd")
	{
		return;
	}
	if (extName == "VK_KHR_performance_query")
	{
		functions.push_back("vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
		functions.push_back("vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
		return;
	}
	if (extName == "VK_KHR_get_surface_capabilities2")
	{
		functions.push_back("vkGetPhysicalDeviceSurfaceCapabilities2KHR");
		functions.push_back("vkGetPhysicalDeviceSurfaceFormats2KHR");
		return;
	}
	if (extName == "VK_KHR_get_display_properties2")
	{
		functions.push_back("vkGetPhysicalDeviceDisplayProperties2KHR");
		functions.push_back("vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
		functions.push_back("vkGetDisplayModeProperties2KHR");
		functions.push_back("vkGetDisplayPlaneCapabilities2KHR");
		return;
	}
	if (extName == "VK_KHR_shader_clock")
	{
		return;
	}
	if (extName == "VK_KHR_swapchain_mutable_format")
	{
		return;
	}
	if (extName == "VK_KHR_shader_terminate_invocation")
	{
		return;
	}
	if (extName == "VK_KHR_fragment_shading_rate")
	{
		functions.push_back("vkGetPhysicalDeviceFragmentShadingRatesKHR");
		return;
	}
	if (extName == "VK_KHR_object_refresh")
	{
		functions.push_back("vkGetPhysicalDeviceRefreshableObjectTypesKHR");
		return;
	}
	if (extName == "VK_KHR_synchronization2")
	{
		return;
	}
	if (extName == "VK_KHR_copy_commands2")
	{
		return;
	}
	if (extName == "VK_EXT_depth_range_unrestricted")
	{
		return;
	}
	if (extName == "VK_EXT_texture_compression_astc_hdr")
	{
		return;
	}
	if (extName == "VK_EXT_astc_decode_mode")
	{
		return;
	}
	if (extName == "VK_EXT_direct_mode_display")
	{
		functions.push_back("vkReleaseDisplayEXT");
		return;
	}
	if (extName == "VK_EXT_display_surface_counter")
	{
		functions.push_back("vkGetPhysicalDeviceSurfaceCapabilities2EXT");
		return;
	}
	if (extName == "VK_EXT_display_control")
	{
		return;
	}
	if (extName == "VK_EXT_discard_rectangles")
	{
		return;
	}
	if (extName == "VK_EXT_conservative_rasterization")
	{
		return;
	}
	if (extName == "VK_EXT_depth_clip_enable")
	{
		return;
	}
	if (extName == "VK_EXT_swapchain_colorspace")
	{
		return;
	}
	if (extName == "VK_EXT_hdr_metadata")
	{
		return;
	}
	if (extName == "VK_EXT_external_memory_dma_buf")
	{
		return;
	}
	if (extName == "VK_EXT_queue_family_foreign")
	{
		return;
	}
	if (extName == "VK_EXT_debug_utils")
	{
		functions.push_back("vkCreateDebugUtilsMessengerEXT");
		functions.push_back("vkDestroyDebugUtilsMessengerEXT");
		functions.push_back("vkSubmitDebugUtilsMessageEXT");
		return;
	}
	if (extName == "VK_EXT_shader_stencil_export")
	{
		return;
	}
	if (extName == "VK_EXT_sample_locations")
	{
		functions.push_back("vkGetPhysicalDeviceMultisamplePropertiesEXT");
		return;
	}
	if (extName == "VK_EXT_blend_operation_advanced")
	{
		return;
	}
	if (extName == "VK_EXT_post_depth_coverage")
	{
		return;
	}
	if (extName == "VK_EXT_image_drm_format_modifier")
	{
		return;
	}
	if (extName == "VK_EXT_filter_cubic")
	{
		return;
	}
	if (extName == "VK_EXT_global_priority")
	{
		return;
	}
	if (extName == "VK_EXT_external_memory_host")
	{
		return;
	}
	if (extName == "VK_EXT_calibrated_timestamps")
	{
		functions.push_back("vkGetPhysicalDeviceCalibrateableTimeDomainsEXT");
		return;
	}
	if (extName == "VK_EXT_vertex_attribute_divisor")
	{
		return;
	}
	if (extName == "VK_EXT_pci_bus_info")
	{
		return;
	}
	if (extName == "VK_EXT_subgroup_size_control")
	{
		return;
	}
	if (extName == "VK_EXT_shader_image_atomic_int64")
	{
		return;
	}
	if (extName == "VK_EXT_memory_budget")
	{
		return;
	}
	if (extName == "VK_EXT_validation_features")
	{
		return;
	}
	if (extName == "VK_EXT_fragment_shader_interlock")
	{
		return;
	}
	if (extName == "VK_EXT_ycbcr_image_arrays")
	{
		return;
	}
	if (extName == "VK_EXT_headless_surface")
	{
		functions.push_back("vkCreateHeadlessSurfaceEXT");
		return;
	}
	if (extName == "VK_EXT_line_rasterization")
	{
		return;
	}
	if (extName == "VK_EXT_shader_atomic_float")
	{
		return;
	}
	if (extName == "VK_EXT_index_type_uint8")
	{
		return;
	}
	if (extName == "VK_EXT_extended_dynamic_state")
	{
		return;
	}
	if (extName == "VK_EXT_shader_demote_to_helper_invocation")
	{
		return;
	}
	if (extName == "VK_EXT_texel_buffer_alignment")
	{
		return;
	}
	if (extName == "VK_EXT_robustness2")
	{
		return;
	}
	if (extName == "VK_EXT_custom_border_color")
	{
		return;
	}
	if (extName == "VK_EXT_ycbcr_2plane_444_formats")
	{
		return;
	}
	if (extName == "VK_EXT_image_robustness")
	{
		return;
	}
	if (extName == "VK_EXT_4444_formats")
	{
		return;
	}
	if (extName == "VK_EXT_vertex_input_dynamic_state")
	{
		return;
	}
	if (extName == "VK_EXT_extended_dynamic_state2")
	{
		return;
	}
	if (extName == "VK_EXT_color_write_enable")
	{
		return;
	}
	DE_FATAL("Extension name not found");
}

void getDeviceExtensionFunctions (uint32_t apiVersion, ::std::string extName, ::std::vector<const char*>& functions)
{
	if (extName == "VK_KHR_surface")
	{
		return;
	}
	if (extName == "VK_KHR_swapchain")
	{
		functions.push_back("vkCreateSwapchainKHR");
		functions.push_back("vkGetSwapchainImagesKHR");
		functions.push_back("vkAcquireNextImageKHR");
		functions.push_back("vkQueuePresentKHR");
		if(apiVersion >= VK_API_VERSION_1_1) functions.push_back("vkGetDeviceGroupPresentCapabilitiesKHR");
		if(apiVersion >= VK_API_VERSION_1_1) functions.push_back("vkGetDeviceGroupSurfacePresentModesKHR");
		if(apiVersion >= VK_API_VERSION_1_1) functions.push_back("vkAcquireNextImage2KHR");
		return;
	}
	if (extName == "VK_KHR_display")
	{
		return;
	}
	if (extName == "VK_KHR_display_swapchain")
	{
		functions.push_back("vkCreateSharedSwapchainsKHR");
		return;
	}
	if (extName == "VK_KHR_external_memory_fd")
	{
		functions.push_back("vkGetMemoryFdKHR");
		functions.push_back("vkGetMemoryFdPropertiesKHR");
		return;
	}
	if (extName == "VK_KHR_external_semaphore_fd")
	{
		functions.push_back("vkImportSemaphoreFdKHR");
		functions.push_back("vkGetSemaphoreFdKHR");
		return;
	}
	if (extName == "VK_KHR_incremental_present")
	{
		return;
	}
	if (extName == "VK_KHR_shared_presentable_image")
	{
		functions.push_back("vkGetSwapchainStatusKHR");
		return;
	}
	if (extName == "VK_KHR_external_fence_fd")
	{
		functions.push_back("vkImportFenceFdKHR");
		functions.push_back("vkGetFenceFdKHR");
		return;
	}
	if (extName == "VK_KHR_performance_query")
	{
		functions.push_back("vkAcquireProfilingLockKHR");
		functions.push_back("vkReleaseProfilingLockKHR");
		return;
	}
	if (extName == "VK_KHR_get_surface_capabilities2")
	{
		return;
	}
	if (extName == "VK_KHR_get_display_properties2")
	{
		return;
	}
	if (extName == "VK_KHR_shader_clock")
	{
		return;
	}
	if (extName == "VK_KHR_swapchain_mutable_format")
	{
		return;
	}
	if (extName == "VK_KHR_shader_terminate_invocation")
	{
		return;
	}
	if (extName == "VK_KHR_fragment_shading_rate")
	{
		functions.push_back("vkCmdSetFragmentShadingRateKHR");
		return;
	}
	if (extName == "VK_KHR_object_refresh")
	{
		functions.push_back("vkCmdRefreshObjectsKHR");
		return;
	}
	if (extName == "VK_KHR_synchronization2")
	{
		functions.push_back("vkCmdSetEvent2KHR");
		functions.push_back("vkCmdResetEvent2KHR");
		functions.push_back("vkCmdWaitEvents2KHR");
		functions.push_back("vkCmdPipelineBarrier2KHR");
		functions.push_back("vkCmdWriteTimestamp2KHR");
		functions.push_back("vkQueueSubmit2KHR");
		return;
	}
	if (extName == "VK_KHR_copy_commands2")
	{
		functions.push_back("vkCmdCopyBuffer2KHR");
		functions.push_back("vkCmdCopyImage2KHR");
		functions.push_back("vkCmdCopyBufferToImage2KHR");
		functions.push_back("vkCmdCopyImageToBuffer2KHR");
		functions.push_back("vkCmdBlitImage2KHR");
		functions.push_back("vkCmdResolveImage2KHR");
		return;
	}
	if (extName == "VK_EXT_depth_range_unrestricted")
	{
		return;
	}
	if (extName == "VK_EXT_texture_compression_astc_hdr")
	{
		return;
	}
	if (extName == "VK_EXT_astc_decode_mode")
	{
		return;
	}
	if (extName == "VK_EXT_direct_mode_display")
	{
		return;
	}
	if (extName == "VK_EXT_display_surface_counter")
	{
		return;
	}
	if (extName == "VK_EXT_display_control")
	{
		functions.push_back("vkDisplayPowerControlEXT");
		functions.push_back("vkRegisterDeviceEventEXT");
		functions.push_back("vkRegisterDisplayEventEXT");
		functions.push_back("vkGetSwapchainCounterEXT");
		return;
	}
	if (extName == "VK_EXT_discard_rectangles")
	{
		functions.push_back("vkCmdSetDiscardRectangleEXT");
		return;
	}
	if (extName == "VK_EXT_conservative_rasterization")
	{
		return;
	}
	if (extName == "VK_EXT_depth_clip_enable")
	{
		return;
	}
	if (extName == "VK_EXT_swapchain_colorspace")
	{
		return;
	}
	if (extName == "VK_EXT_hdr_metadata")
	{
		functions.push_back("vkSetHdrMetadataEXT");
		return;
	}
	if (extName == "VK_EXT_external_memory_dma_buf")
	{
		return;
	}
	if (extName == "VK_EXT_queue_family_foreign")
	{
		return;
	}
	if (extName == "VK_EXT_debug_utils")
	{
		functions.push_back("vkSetDebugUtilsObjectNameEXT");
		functions.push_back("vkSetDebugUtilsObjectTagEXT");
		functions.push_back("vkQueueBeginDebugUtilsLabelEXT");
		functions.push_back("vkQueueEndDebugUtilsLabelEXT");
		functions.push_back("vkQueueInsertDebugUtilsLabelEXT");
		functions.push_back("vkCmdBeginDebugUtilsLabelEXT");
		functions.push_back("vkCmdEndDebugUtilsLabelEXT");
		functions.push_back("vkCmdInsertDebugUtilsLabelEXT");
		return;
	}
	if (extName == "VK_EXT_shader_stencil_export")
	{
		return;
	}
	if (extName == "VK_EXT_sample_locations")
	{
		functions.push_back("vkCmdSetSampleLocationsEXT");
		return;
	}
	if (extName == "VK_EXT_blend_operation_advanced")
	{
		return;
	}
	if (extName == "VK_EXT_post_depth_coverage")
	{
		return;
	}
	if (extName == "VK_EXT_image_drm_format_modifier")
	{
		functions.push_back("vkGetImageDrmFormatModifierPropertiesEXT");
		return;
	}
	if (extName == "VK_EXT_filter_cubic")
	{
		return;
	}
	if (extName == "VK_EXT_global_priority")
	{
		return;
	}
	if (extName == "VK_EXT_external_memory_host")
	{
		functions.push_back("vkGetMemoryHostPointerPropertiesEXT");
		return;
	}
	if (extName == "VK_EXT_calibrated_timestamps")
	{
		functions.push_back("vkGetCalibratedTimestampsEXT");
		return;
	}
	if (extName == "VK_EXT_vertex_attribute_divisor")
	{
		return;
	}
	if (extName == "VK_EXT_pci_bus_info")
	{
		return;
	}
	if (extName == "VK_EXT_subgroup_size_control")
	{
		return;
	}
	if (extName == "VK_EXT_shader_image_atomic_int64")
	{
		return;
	}
	if (extName == "VK_EXT_memory_budget")
	{
		return;
	}
	if (extName == "VK_EXT_validation_features")
	{
		return;
	}
	if (extName == "VK_EXT_fragment_shader_interlock")
	{
		return;
	}
	if (extName == "VK_EXT_ycbcr_image_arrays")
	{
		return;
	}
	if (extName == "VK_EXT_headless_surface")
	{
		return;
	}
	if (extName == "VK_EXT_line_rasterization")
	{
		functions.push_back("vkCmdSetLineStippleEXT");
		return;
	}
	if (extName == "VK_EXT_shader_atomic_float")
	{
		return;
	}
	if (extName == "VK_EXT_index_type_uint8")
	{
		return;
	}
	if (extName == "VK_EXT_extended_dynamic_state")
	{
		functions.push_back("vkCmdSetCullModeEXT");
		functions.push_back("vkCmdSetFrontFaceEXT");
		functions.push_back("vkCmdSetPrimitiveTopologyEXT");
		functions.push_back("vkCmdSetViewportWithCountEXT");
		functions.push_back("vkCmdSetScissorWithCountEXT");
		functions.push_back("vkCmdBindVertexBuffers2EXT");
		functions.push_back("vkCmdSetDepthTestEnableEXT");
		functions.push_back("vkCmdSetDepthWriteEnableEXT");
		functions.push_back("vkCmdSetDepthCompareOpEXT");
		functions.push_back("vkCmdSetDepthBoundsTestEnableEXT");
		functions.push_back("vkCmdSetStencilTestEnableEXT");
		functions.push_back("vkCmdSetStencilOpEXT");
		return;
	}
	if (extName == "VK_EXT_shader_demote_to_helper_invocation")
	{
		return;
	}
	if (extName == "VK_EXT_texel_buffer_alignment")
	{
		return;
	}
	if (extName == "VK_EXT_robustness2")
	{
		return;
	}
	if (extName == "VK_EXT_custom_border_color")
	{
		return;
	}
	if (extName == "VK_EXT_ycbcr_2plane_444_formats")
	{
		return;
	}
	if (extName == "VK_EXT_image_robustness")
	{
		return;
	}
	if (extName == "VK_EXT_4444_formats")
	{
		return;
	}
	if (extName == "VK_EXT_vertex_input_dynamic_state")
	{
		functions.push_back("vkCmdSetVertexInputEXT");
		return;
	}
	if (extName == "VK_EXT_extended_dynamic_state2")
	{
		functions.push_back("vkCmdSetPatchControlPointsEXT");
		functions.push_back("vkCmdSetRasterizerDiscardEnableEXT");
		functions.push_back("vkCmdSetDepthBiasEnableEXT");
		functions.push_back("vkCmdSetLogicOpEXT");
		functions.push_back("vkCmdSetPrimitiveRestartEnableEXT");
		return;
	}
	if (extName == "VK_EXT_color_write_enable")
	{
		functions.push_back("vkCmdSetColorWriteEnableEXT");
		return;
	}
	DE_FATAL("Extension name not found");
}

::std::string instanceExtensionNames[] =
{
	"VK_KHR_surface",
	"VK_KHR_display",
	"VK_KHR_performance_query",
	"VK_KHR_get_surface_capabilities2",
	"VK_KHR_get_display_properties2",
	"VK_KHR_fragment_shading_rate",
	"VK_EXT_direct_mode_display",
	"VK_EXT_display_surface_counter",
	"VK_EXT_calibrated_timestamps",
	"VK_EXT_headless_surface"
};

::std::string deviceExtensionNames[] =
{
	"VK_KHR_swapchain",
	"VK_KHR_display_swapchain",
	"VK_KHR_external_memory_fd",
	"VK_KHR_external_semaphore_fd",
	"VK_KHR_shared_presentable_image",
	"VK_KHR_external_fence_fd",
	"VK_KHR_object_refresh",
	"VK_KHR_synchronization2",
	"VK_KHR_copy_commands2",
	"VK_EXT_display_control",
	"VK_EXT_discard_rectangles",
	"VK_EXT_hdr_metadata",
	"VK_EXT_debug_utils",
	"VK_EXT_sample_locations",
	"VK_EXT_image_drm_format_modifier",
	"VK_EXT_external_memory_host",
	"VK_EXT_line_rasterization",
	"VK_EXT_extended_dynamic_state",
	"VK_EXT_vertex_input_dynamic_state",
	"VK_EXT_extended_dynamic_state2",
	"VK_EXT_color_write_enable"
};