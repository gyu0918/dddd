package com.roulette.roulette.myPage;

import com.roulette.roulette.domain.Code;
import com.roulette.roulette.domain.Member;
import com.roulette.roulette.domain.Post;
import org.junit.jupiter.api.Test;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.Mockito.when;

////@SpringBootTest
//public class MyPageServiceTest {
//
//    @Mock
//    private MyMemberRepository myMemberRepository;
//
//    @Mock
//    private MyPostRepository myPostRepository;
//
//    @Mock
//    private MyCodeRepository myCodeRepository;
//
//    @InjectMocks
//    private MyPageService myPageService;
//
//    @Test
//    public void testGetMemberDTO() {
//        // Mock 데이터 설정
//        Long memberId = 1L;
//        Member member = new Member("John", "john@example.com");
//        when(myMemberRepository.findById(memberId)).thenReturn(Optional.of(member));
//
//        // 테스트
//        MemberDTO memberDTO = myPageService.getMemberDTO(memberId);
//
//        // 결과 검증
//        assertEquals(member.getName(), memberDTO.getName());
//        assertEquals(member.getEmail(), memberDTO.getEmail());
//    }
//
//    @Test
//    public void testGetMyPageData() {
//        // Mock 데이터 설정
//        Long memberId = 1L;
//        Member member = new Member("John", "john@example.com");
//        when(myMemberRepository.findById(memberId)).thenReturn(Optional.of(member));
//
//        List<Post> postList = new ArrayList<>();
//        postList.add(new Post(1L, "Title", "Content", member));
//        when(myPostRepository.findAllByMemberId(memberId)).thenReturn(postList);
//
//        // 테스트
//        MyPageDTO myPageDTO = myPageService.getMyPageData(memberId);
//
//        // 결과 검증
//        assertEquals(member.getEmail(), myPageDTO.getEmail());
//        assertEquals(postList.size(), myPageDTO.getPostList().size());
//        assertEquals(postList.get(0).getTitle(), myPageDTO.getPostList().get(0).getTitle());
//        // 나머지 필드도 동일하게 검증
//    }
//
//    @Test
//    public void testGetMyCodeData() {
//        // Mock 데이터 설정
//        Long memberId = 1L;
//        List<Code> codeList = new ArrayList<>();
//        codeList.add(new Code(1L, "URL1", "2022-04-21", "CodeName1"));
//        codeList.add(new Code(2L, "URL2", "2022-04-22", "CodeName2"));
//        when(myCodeRepository.findAllByMemberId(memberId)).thenReturn(codeList);
//
//        // 테스트
//        MyCodeDTO myCodeDTO = myPageService.getMyCodeData(memberId);
//
//        // 결과 검증
//        assertEquals(codeList.get(0).getCodeUrl(), myCodeDTO.getCodeURL());
//        assertEquals(codeList.get(0).getCreateTime(), myCodeDTO.getCreatedTime());
//        assertEquals(codeList.size(), myCodeDTO.getCodeList().size());
//        assertEquals(codeList.get(0).getCodeName(), myCodeDTO.getCodeList().get(0).getCodeName());
//        // 나머지 필드도 동일하게 검증
//    }
//}