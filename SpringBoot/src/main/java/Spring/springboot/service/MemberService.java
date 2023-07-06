package Spring.springboot.service;

import Spring.springboot.domain.Member;
import Spring.springboot.repository.MemberRepository;
import Spring.springboot.repository.MemoryMemberRepository;

import java.util.List;
import java.util.Optional;

public class MemberService  {

    private final MemberRepository memberRepository = new MemoryMemberRepository();


    /**
     * 회원가입
     */
    public Long join(Member member){
        //같은 이름의 회원 중복 No
        //밑의 MemberRepositroy.findByName(member.getName())이부분을 커멘드 + 옵션 + v 를 이용해 옵셔널처리 가능
        validateDuplicateMember(member);
        memberRepository.save(member);
        return member.getId();
    }

    private void validateDuplicateMember(Member member) {
        memberRepository.findByName(member.getName())
                        .ifPresent(m-> {
                            throw new IllegalStateException("이미 존재하는 회원입니다.");
                        });
    }
    /**
     * 전체 회원 조회
     */

    public List<Member> findMembers(){
        return memberRepository.findAll();
    }

    public Optional<Member> findOne(Long memberId){
        return memberRepository.findById(memberId);
    }
}
