package Spring.springboot.repository;

import Spring.springboot.domain.Member;

import java.util.*;

public class MemoryMemberRepository implements MemberRepository{
    private static Map<Long, Member> store = new HashMap<>();  // 동시성문제 생각해보기!!
    private static long sequence = 0L;

    @Override
    public Member save(Member member) {
        member.setId(++sequence);
        store.put(member.getId(), member);
        return member;
    }

    @Override
    public Optional<Member> findById(Long id) {
        return Optional.ofNullable(store.get(id));                  //null이 반환될경우도 있기 때문에 Optional을 감싸서 사용한다.
    }

    /*@Override
    public Optional<Member> findByName(String name) {
        return store.values().stream()                                          //java while문법
                .filter(member -> member.getName().equals(name))
                .findAny();
    }*/

    @Override
    public List<Member> findAll() {
        return new ArrayList<>(store.values());                             //java 실무에서는 List많이 쓴다.
    }
}
