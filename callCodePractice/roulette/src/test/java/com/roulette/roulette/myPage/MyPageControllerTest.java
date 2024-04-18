package com.roulette.roulette.myPage;


import com.roulette.roulette.myPage.myDTO.MemberDTO;
import com.roulette.roulette.myPage.myDTO.MyCodeDTO;
import com.roulette.roulette.myPage.myDTO.MyPageDTO;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.AutoConfigureMockMvc;
import org.springframework.boot.test.autoconfigure.web.servlet.WebMvcTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.security.test.context.support.WithMockUser;
import org.springframework.test.context.junit.jupiter.SpringExtension;
import org.springframework.test.web.servlet.MockMvc;

import static org.mockito.ArgumentMatchers.anyLong;
import static org.mockito.Mockito.when;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.get;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.*;

@ExtendWith(SpringExtension.class)
@WebMvcTest(MyPageController.class)
@AutoConfigureMockMvc
class MyPageControllerTest {

    @Autowired
    private MockMvc mockMvc;

    @MockBean
    private MyPageService myPageService;

    @Test
    @WithMockUser
    void testGoMyPage() throws Exception {
        // Given
        Long memberId = 1L;
        when(myPageService.getMemberDTO(anyLong())).thenReturn(new MemberDTO());

        // When & Then
        mockMvc.perform(get("/mypage/{member_id}", memberId))
                .andExpect(status().isOk())
                .andExpect(jsonPath("$.code").value(200));
    }

    @Test
    @WithMockUser
    void testGetAllMembers() throws Exception {
        // Given
        Long memberId = 1L;
        when(myPageService.getMemberDTO(anyLong())).thenReturn(new MemberDTO());

        // When & Then
        mockMvc.perform(get("/mypage/member/{member_id}", memberId))
                .andExpect(status().isOk());
    }

    @Test
    @WithMockUser
    void testGetMyPost() throws Exception {
        // Given
        Long memberId = 1L;
        when(myPageService.getMyPageData(anyLong())).thenReturn(new MyPageDTO());

        // When & Then
        mockMvc.perform(get("/mypage/list/{member_id}", memberId))
                .andExpect(status().isOk());
    }

    @Test
    @WithMockUser
    void testGetMyCode() throws Exception {
        // Given
        Long memberId = 1L;
        when(myPageService.getMyCodeData(anyLong())).thenReturn(new MyCodeDTO());

        // When & Then
        mockMvc.perform(get("/mypage/code/{member_id}", memberId))
                .andExpect(status().isOk());
    }
}